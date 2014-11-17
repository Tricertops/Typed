//
//  main.m
//  Test
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

@import Foundation;
#import "Typed.h"



TGenerate(TArray(NSString),)
TAssociativeGenerate(NSString,*, TArray(NSString),)



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
#pragma mark - TArray
        {
            //! Creating:
            TArray(NSString) strings = TArrayMake(NSString, @"Apple", @"Orange", @"Pear");
            strings = [TArrayAlloc(NSString) initWithArray:strings];
//          TArray(NSString) strings = TArrayMake(NSString, @"Apple", @42);
            
            //! Casting to NSArray:
            NSArray *objects = strings;
            NSArray *untyped = strings.untyped;
//          TArray(NSString) strings = [NSArray new];
            
            //! Accessing objects:
            NSString *apple = strings.firstObject;
            NSString *orange = strings[1];
//          NSURL *websiteURL = strings.firstObject;
//          NSNumber *ultimateAnswer = strings[1];
            
            //! Enumerating objects:
            TForIn(fruit, strings) {
                NSString *lowercase = fruit.lowercaseString;
//                NSURL *host = fruit.host;
            }
            
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
            NSSet *untyped = strings.untyped;
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
#pragma mark - TDictionary
        {
            //! Creating:
            TDictionary(NSString, NSNumber) fruitCounts = TDictionaryMake(NSString, NSNumber,
                                                                          TPair(@"Apple", @5),
                                                                          TPair(@"Orange", @2),
                                                                          TPair(@"Pear", @4));
//            fruitCounts = TDictionaryMake(NSString, NSNumber,
//                                          TPair(@"Apple", @"5"),
//                                          TPair(@0, @0),
//                                          TPair(@"Pear", @4));
            
            //! Casting to NSDictionary:
            NSDictionary *dictionary = fruitCounts;
            NSDictionary *untyped = fruitCounts.untyped;
//            fruitCounts = [NSDictionary new];
            
            //! Lookup:
            NSUInteger apples = fruitCounts[@"Apple"].unsignedIntegerValue;
//            NSURL *website = fruitCounts[@"Apple"];
//            NSNumber *answer = fruitCounts[@42];
            
            //! Accessing keys and values:
            TArray(NSString) fruits = fruitCounts.allKeys;
            TArray(NSNumber) counts = fruitCounts.allValues;
//            TArray(NSURL) websites = fruitCounts.allKeys;
//            TArray(NSString) titles = fruitCounts.allValues;
        }
        
#pragma mark - Nested
        {
            TDictionary(NSString, TArray(NSString)) keywords = (NSStringToNSStringArrayDictionary)
            @{
              @"Apple": @[@"Mac",@"iPhone",@"iPad"],
              @"Orange": @[@"Carrier",@"Cellular",@"Phone"],
              @"Pear": @[@"Fruit",@"Sweet",@"Food"],
              };
            
            TArray(NSString) appleKeywords = keywords[@"Apple"];
            NSUInteger orangeCount = keywords[@"Orange"].count;
            NSString *pearKeyword = keywords[@"Pear"][2].lowercaseString;
            
//            TArray(NSNumber) answerKeywords = keywords[@42];
//            NSString *websiteHost = keywords[@"Website"].host;
            
        }
    }
    return EXIT_SUCCESS;
}


