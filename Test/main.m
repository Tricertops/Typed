//
//  main.m
//  Test
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "Typed.h"


TArrayGenerate(NSNumber)


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        TArray(NSString) names = TArrayMake(NSString, @"Martin", @"George");
        TArray(NSNumber) counts = TArrayMake(NSNumber, @42 );
        __unused NSArray *untyped = (NSArray *)names;
        __unused NSString *me = names[0];
        __unused NSNumber *ultimate = counts[0];
        names = [names arrayByAddingObject:@"George"];
        
        
//        __unused NSNumber *notMe = names[0];
//        __unused NSString *notUltimate = counts[0];
//        counts = names;
        
    }
    return EXIT_SUCCESS;
}
