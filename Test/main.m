//
//  main.m
//  Test
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

@import Foundation;
@import AppKit;
#import "Typed.h"



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        //! Some example usage:
        
        let name = @"Martin"; // NSString (const)
        var mutable = name.mutableCopy; // NSMutableString
        
        NSArray<NSString *> *letters = @[@"A", @"B", @"C"];
        
        foreach (letter, letters) {  } // NSString
        
    }
    return EXIT_SUCCESS;
}


