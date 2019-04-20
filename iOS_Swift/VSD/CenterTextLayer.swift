//
//  CenterTextLayer.swift
//  VSD
//
//  Created by Natan Facchin on 4/20/19.
//  Copyright © 2019 Natan Facchin. All rights reserved.
//

import Foundation

#if os(iOS) || os(tvOS)
import UIKit
#elseif os(OSX)
import AppKit
#endif

public class CenterTextLayer: CATextLayer {
    
    public override init() {
        super.init()
    }
    
    public override init(layer: Any) {
        super.init(layer: layer)
    }
    
    public required init(coder aDecoder: NSCoder) {
        super.init(layer: aDecoder)
    }
    
    public override func draw(in ctx: CGContext) {
        #if os(iOS) || os(tvOS)
        let multiplier = CGFloat(1)
        #elseif os(OSX)
        let multiplier = CGFloat(-1)
        #endif
        let yDiff = (bounds.size.height - ((string as? NSAttributedString)?.size().height ?? fontSize)) / 2 * multiplier
        
        ctx.saveGState()
        ctx.translateBy(x: 0.0, y: yDiff)
        super.draw(in: ctx)
        ctx.restoreGState()
    }
}
