//
//  TRandom.m
//  Typed
//
//  Created by Martin Kiss on 7.3.15.
//  Copyright (c) 2015 Triceratops. All rights reserved.
//

@import Foundation;


#define _TRandom(COUNT)     arc4random_uniform((u_int32_t)(COUNT))





@implementation NSMutableArray (TRandom)



- (NSUInteger)randomInsertionIndex {
    return _TRandom(self.count + 1);
}


- (void)randomizeObjects {
    for (NSInteger index = self.count - 1; index > 0; index --)
        [self exchangeObjectAtIndex:index withObjectAtIndex:_TRandom(index + 1)];
}



@end





@implementation NSArray (TRandom)



- (id)randomObject {
    return [self objectAtIndex:self.randomIndex];
}


- (NSUInteger)randomIndex {
    return _TRandom(self.count);
}


- (NSArray *)arrayByRandomizingObjects {
    NSMutableArray *mutable = [self mutableCopy];
    [mutable randomizeObjects];
    return mutable;
}



@end





@implementation NSMutableOrderedSet (TRandom)



- (NSUInteger)randomInsertionIndex {
    return _TRandom(self.count + 1);
}


- (void)randomizeObjects {
    for (NSInteger index = self.count - 1; index > 0; index --)
        [self exchangeObjectAtIndex:index withObjectAtIndex:_TRandom(index + 1)];
}



@end





@implementation NSOrderedSet (TRandom)



- (id)randomObject {
    return [self objectAtIndex:self.randomIndex];
}


- (NSUInteger)randomIndex {
    return _TRandom(self.count);
}


- (NSOrderedSet *)orderedSetByRandomizingObjects {
    NSMutableOrderedSet *mutable = [self mutableCopy];
    [mutable randomizeObjects];
    return mutable;
}



@end





@implementation NSPointerArray (TRandom)


- (id)randomObject {
    return [self pointerAtIndex:self.randomIndex];
}


- (NSUInteger)randomIndex {
    return _TRandom(self.count);
}


@end


