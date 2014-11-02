//
//  main.m
//  Test
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "Typed.h"



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        //! Creating array:
        TArray(NSString) strings = TArrayMake(NSString, @"Apple", @"Orange", @"Pear");
//        TArray(NSString) strings = TArrayMake(NSString, @"Apple", @42);
//        TArray(NSString) strings = @[ @"Apple", @42 ];

        //! Casting to NSArray:
        NSArray *objects = (NSArray *)strings;
//        NSArray *objects = strings;
        
        //! Accessing objects:
        NSString *apple = strings.firstObject;
        NSString *orange = strings[1];
//        NSURL *websiteURL = strings.firstObject;
//        NSNumber *ultimateAnswer = strings[1];
        
        //! Finding objects:
        BOOL containsApple = [strings containsObject:@"Apple"];
        NSUInteger orangeIndex = [strings indexOfObject:@"Orange"];
//        BOOL containsUltimateAnswer = [strings containsObject:@42];
//        NSUInteger websiteURLIndex = [strings indexOfObject:websiteURL];
        
        //! Deriving arrays:
        strings = [strings copy];
        strings = [strings arrayByAddingObject:@"Peach"];
        strings = [strings subarrayWithRange:NSMakeRange(0, 3)];
//        TArray(NSURL) URLs = [strings copy];
//        TArray(NSDate) dates = [strings arrayByAddingObject:@"Peach"];
//        TArray(NSNumber) answers = [strings subarrayWithRange:NSMakeRange(0, 3)];
        
        TMutableArray(NSString) mutableStrings = [strings mutableCopy];
        
        [mutableStrings addObject:@"Pineapple"];
        [mutableStrings replaceObjectAtIndex:2 withObject:@"Lemon"];
//        [mutableStrings addObject:@42];
//        [mutableStrings replaceObjectAtIndex:2 withObject:websiteURL];
        
    }
    return EXIT_SUCCESS;
}


