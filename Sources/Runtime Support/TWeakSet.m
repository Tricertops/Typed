//
//  TWeakSet.m
//  Typed
//
//  Created by Martin Kiss on 15.2.15.
//  Copyright (c) 2015 Triceratops. All rights reserved.
//

#import <Foundation/NSHashTable.h>
#import "TWeakSet.h"



//! This category provides implementations for renamed method of NSHashTable, a.k.a. TWeakSet.



@implementation NSHashTable (TWeakSet)





- (NSSet *)strong {
    return self.setRepresentation;
}


- (BOOL)isEqualToWeakSet:(NSHashTable *)other {
    return [self isEqualToHashTable: other];
}


- (BOOL)isSubsetOfWeakSet:(NSHashTable *)other {
    return [self isSubsetOfHashTable: other];
}


- (BOOL)intersectsWeakSet:(NSHashTable *)other {
    return [self intersectsHashTable: other];
}





- (void)unionWeakSet:(NSHashTable *)other {
    [self unionHashTable: other];
}


- (void)intersectWeakSet:(NSHashTable *)other {
    [self intersectHashTable:other];
}


- (void)minusWeakSet:(NSHashTable *)other {
    [self minusHashTable:other];
}





@end


