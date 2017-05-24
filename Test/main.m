//
//  TypedCollectionLiterals.h
//  Typed
//
//  Created by Martin Kiss on 24 May 2017.
//  https://github.com/Tricertops/Typed
//
//  The MIT License (MIT)
//  Copyright © 2017 Martin Kiss
//

@import Foundation;
@import AppKit;
#import "Typed.h"



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        //! Some example usage:
        
        let name = @"Martin"; // NSString * const
        var mutableName = name.mutableCopy; // NSMutableString *
        
        let letters = NSArray(@"A", @"B", @"C"); // NSArray<NSString *> * const
        var mutableLetters = letters.mutableCopy; // NSMutableArray<NSString *> *
        
        foreach (letter, letters) {
            // NSString *
        }
        
    }
    return EXIT_SUCCESS;
}


