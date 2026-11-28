#!/usr/bin/env swift

import AppKit
import Foundation

let arguments = CommandLine.arguments
guard arguments.count == 3 else {
    fputs("usage: render_cc_screenshots.swift INPUT_DIR OUTPUT_DIR\n", stderr)
    exit(2)
}

let inputDirectory = URL(fileURLWithPath: arguments[1], isDirectory: true)
let outputDirectory = URL(fileURLWithPath: arguments[2], isDirectory: true)
try FileManager.default.createDirectory(at: outputDirectory, withIntermediateDirectories: true)

let font = NSFont(name: "Menlo", size: 13) ?? NSFont.monospacedSystemFont(ofSize: 13, weight: .regular)
let foreground = NSColor(calibratedRed: 0.92, green: 0.94, blue: 0.97, alpha: 1)
let background = NSColor(calibratedRed: 30.0 / 255.0, green: 38.0 / 255.0, blue: 51.0 / 255.0, alpha: 1)
let attributes: [NSAttributedString.Key: Any] = [.font: font, .foregroundColor: foreground]
let lineHeight: CGFloat = 17
let horizontalPadding: CGFloat = 4
let verticalPadding: CGFloat = 4
let maximumColumns = 96

func wrapped(_ source: String) -> [String] {
    var result: [String] = []
    for rawLine in source.replacingOccurrences(of: "\t", with: "    ").split(separator: "\n", omittingEmptySubsequences: false) {
        var line = String(rawLine)
        if line.isEmpty {
            result.append("")
            continue
        }
        while line.count > maximumColumns {
            let cut = line.index(line.startIndex, offsetBy: maximumColumns)
            result.append(String(line[..<cut]))
            line = String(line[cut...])
        }
        result.append(line)
    }
    if result.last == "" { result.removeLast() }
    return result
}

let fileURLs = try FileManager.default.contentsOfDirectory(
    at: inputDirectory,
    includingPropertiesForKeys: nil,
    options: [.skipsHiddenFiles]
).filter { $0.pathExtension == "txt" }.sorted { $0.lastPathComponent < $1.lastPathComponent }

for fileURL in fileURLs {
    let source = try String(contentsOf: fileURL, encoding: .utf8)
    let lines = wrapped(source)
    let measuredWidths = lines.map { (String($0) as NSString).size(withAttributes: attributes).width }
    let contentWidth = measuredWidths.max() ?? 0
    let width = Int(ceil(max(610, min(820, contentWidth + horizontalPadding * 2))))
    let height = Int(ceil(max(34, CGFloat(lines.count) * lineHeight + verticalPadding * 2)))

    guard let bitmap = NSBitmapImageRep(
        bitmapDataPlanes: nil,
        pixelsWide: width,
        pixelsHigh: height,
        bitsPerSample: 8,
        samplesPerPixel: 4,
        hasAlpha: true,
        isPlanar: false,
        colorSpaceName: .deviceRGB,
        bytesPerRow: 0,
        bitsPerPixel: 0
    ) else {
        throw NSError(domain: "ScreenshotRenderer", code: 1)
    }

    NSGraphicsContext.saveGraphicsState()
    NSGraphicsContext.current = NSGraphicsContext(bitmapImageRep: bitmap)
    background.setFill()
    NSBezierPath(rect: NSRect(x: 0, y: 0, width: width, height: height)).fill()
    for (index, line) in lines.enumerated() {
        let y = CGFloat(height) - verticalPadding - lineHeight * CGFloat(index + 1) + 2
        (line as NSString).draw(at: NSPoint(x: horizontalPadding, y: y), withAttributes: attributes)
    }
    NSGraphicsContext.restoreGraphicsState()

    guard let png = bitmap.representation(using: .png, properties: [:]) else {
        throw NSError(domain: "ScreenshotRenderer", code: 2)
    }
    let outputURL = outputDirectory.appendingPathComponent(fileURL.deletingPathExtension().lastPathComponent + ".png")
    try png.write(to: outputURL)
}

print("rendered \(fileURLs.count) screenshots")
