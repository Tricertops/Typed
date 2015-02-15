//
//  TWeakSet.h
//  Typed
//
//  Created by Martin Kiss on 15.2.15.
//  Copyright (c) 2015 Triceratops. All rights reserved.
//

#import "TCollections.h"



#define _TWeakSetCreateProtocol(Element, Ptr) \
/*! Types */ \
_TSetForward(Element) \
/*! NSHashTable Interface */ \
_TWeakSetForward(Element) \
@protocol TWeakSet_##Element <_TWeakProtocols> \
- (TWeakSet(Element))self; \
- (NSHashTable *)untyped; \
- (Element Ptr)T_Element; \
- (Element Ptr)T_Enumeration; \
/*! Accessing Content */ \
@property (readonly) NSUInteger count; \
@property (readonly, copy) TArray(Element) allObjects; \
- (Element Ptr )anyObject; \
- (BOOL)containsObject:(Element Ptr )object; \
- (Element Ptr )member:(Element Ptr )object; \
- (NSEnumerator *)objectEnumerator; \
@property(readonly, copy) TSet(Element) setRepresentation; \
/*! Comparing Sets */ \
- (BOOL)isEqual:(TWeakSet(Element))other; \
- (BOOL)isEqualToWeakSet:(TWeakSet(Element))other; \
- (BOOL)isSubsetOfWeakSet:(TWeakSet(Element))other; \
- (BOOL)intersectsWeakSet:(TWeakSet(Element))other; \
/*! Manipulating Membership */ \
- (BOOL)addObject:(Element Ptr)object; \
- (void)removeObject:(Element Ptr)object; \
- (void)removeAllObjects; \
/*! Set Operations */ \
- (void)unionWeakSet:(TWeakSet(Element))other; \
- (void)intersectWeakSet:(TWeakSet(Element))other; \
- (void)minusWeakSet:(TWeakSet(Element))other; \
/*! Copying a Set */ \
- (TWeakSet(Element))copy; \
- (TWeakSet(Element))copyWithZone:(NSZone *)zone; \
/*! Creating a Description */ \
@property (readonly, copy) NSString *description; \
@end


