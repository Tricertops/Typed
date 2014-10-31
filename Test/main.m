//
//  main.m
//  Test
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "Typed.h"


TArrayGenerate(NSString)
TArrayGenerate(NSNumber)


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        TArray(NSString) *names = @[ @"Martin" ];
        TArray(NSNumber) *counts = @[ @42 ];
        __unused NSString *me = [names objectAtIndex:0];
        __unused NSString *ultimate = [counts objectAtIndex:0];
        __unused NSArray *untyped = (NSArray *)counts;
        
//        __unused NSNumber *notMe = [names objectAtIndex:0];
//        __unused NSNumber *notUltimate = [counts objectAtIndex:0];
//        counts = names;
        
    }
    return EXIT_SUCCESS;
}
