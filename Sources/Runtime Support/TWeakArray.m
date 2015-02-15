//
//  TWeakArray.m
//  Typed
//
//  Created by Martin Kiss on 15.2.15.
//  Copyright (c) 2015 Triceratops. All rights reserved.
//

#import <Foundation/NSPointerArray.h>





@implementation NSPointerArray (TWeakArray)





- (NSArray *)strong {
    return self.allObjects;
}


- (id)objectAtIndex:(NSUInteger)index {
    return [self pointerAtIndex:index];
}


- (id)objectAtIndexedSubscript:(NSUInteger)index {
    return [self pointerAtIndex:index];
}





- (void)addObject:(id)object {
    [self addPointer:(__bridge void *)object];
}


- (void)insertObject:(id)object atIndex:(NSUInteger)index {
    [self insertPointer:(__bridge void *)object atIndex:index];
}





- (void)removeObjectAtIndex:(NSUInteger)index {
    [self removePointerAtIndex:index];
}





- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)object {
    [self replacePointerAtIndex:index withPointer:(__bridge void *)object];
}


- (void)setObject:(id)object atIndexedSubscript:(NSUInteger)index {
    if (index == self.count) {
        [self addPointer:(__bridge void *)object];
    }
    else {
        [self replacePointerAtIndex:index withPointer:(__bridge void *)object];
    }
}





@end


