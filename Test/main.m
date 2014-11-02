//
//  main.m
//  Test
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

@import Foundation;
#import "Typed.h"



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
#pragma mark - TArray
        {
            //! Creating:
            TArray(NSString) strings = TArrayMake(NSString, @"Apple", @"Orange", @"Pear");
            strings = [TArrayAlloc(NSString) initWithArray:strings];
//          TArray(NSString) strings = TArrayMake(NSString, @"Apple", @42);
            
            //! Casting to NSArray:
            NSArray *objects = (NSArray *)strings;
//          TArray(NSString) strings = [NSArray new];
            
            //! Accessing objects:
            NSString *apple = strings.firstObject;
            NSString *orange = strings[1];
//          NSURL *websiteURL = strings.firstObject;
//          NSNumber *ultimateAnswer = strings[1];
            
            //! Finding objects:
            BOOL containsApple = [strings containsObject:@"Apple"];
            NSUInteger orangeIndex = [strings indexOfObject:@"Orange"];
//          BOOL containsUltimateAnswer = [strings containsObject:@42];
//          NSUInteger websiteURLIndex = [strings indexOfObject:@[]];
            
            //! Deriving arrays:
            strings = [strings copy];
            strings = [strings arrayByAddingObject:@"Peach"];
            strings = [strings subarrayWithRange:NSMakeRange(0, 3)];
//          TArray(NSURL) URLs = [strings copy];
//          TArray(NSDate) dates = [strings arrayByAddingObject:@"Peach"];
//          TArray(NSNumber) answers = [strings subarrayWithRange:NSMakeRange(0, 3)];
            
            //! Mutating array:
            TMutableArray(NSString) mutableStrings = [strings mutableCopy];
            
            [mutableStrings addObject:@"Pineapple"];
            [mutableStrings replaceObjectAtIndex:2 withObject:@"Lemon"];
//          [mutableStrings addObject:@42];
//          [mutableStrings replaceObjectAtIndex:2 withObject:@[]];
        }
        
#pragma mark - TSet
        {
            //! Creating:
            TSet(NSString) strings = TSetMake(NSString, @"Apple", @"Orange", @"Pear");
            strings = [TSetAlloc(NSString) initWithArray:[strings allObjects]];
//          TSet(NSString) strings = TSetMake(NSString, @"Apple", @42);

            //! Casting to NSSet:
            NSSet *objects = strings;
//          strings = [NSSet new];
            
            //! Accessing objects:
            NSString *fruit = [strings anyObject];
            TArray(NSString) fruits = [strings allObjects];
//          NSNumber *answer = [strings anyObject];
//          TArray(NSURL) websiteURLs = [strings allObjects];
            
            //! Deriving collections:
            NSSortDescriptor *descriptor = [NSSortDescriptor sortDescriptorWithKey:@"self" ascending:YES];
            TArray(NSSortDescriptor) descriptors = TArrayMake(NSSortDescriptor, descriptor);
            
            strings = [strings setByAddingObject:@"Peach"];
            TArray(NSString) sorted = [strings sortedArrayUsingDescriptors:descriptors];
//          strings = [strings setByAddingObject:@42];
//          TArray(NSNumber) sorted = [strings sortedArrayUsingDescriptors:descriptors];
            
            //! Mutating set:
            TMutableSet(NSString) mutableStrings = [strings mutableCopy];
            
            [mutableStrings addObject:@"Pineapple"];
            [mutableStrings removeObject:@"Pear"];
//          [mutableStrings addObject:@42];
//          [mutableStrings removeObject:@[]];
            
        }
    }
    return EXIT_SUCCESS;
}


