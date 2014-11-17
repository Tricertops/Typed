//
//  TMutableOrderedSet.h
//  Typed
//
//  Created by Martin Kiss on 4.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TOrderedSet.h"



#define _TMutableOrderedSetCreateProtocol(Element, Ptr) \
/*! NSMutableOrderedSet Interface */ \
_TMutableOrderedSetForward(Element) \
@protocol TMutableOrderedSet_##Element <TOrderedSet_##Element> \
- (TMutableOrderedSet(Element))self; \
- (NSMutableOrderedSet *)untyped; \
/*! Initializing an Ordered Set */ \
- (TMutableOrderedSet(Element))initWithArray:(TArray(Element))array; \
- (TMutableOrderedSet(Element))initWithArray:(TArray(Element))set copyItems:(BOOL)flag; \
- (TMutableOrderedSet(Element))initWithArray:(TArray(Element))set range:(NSRange)range copyItems:(BOOL)flag; \
- (TMutableOrderedSet(Element))initWithObject:(Element Ptr )object; \
- (TMutableOrderedSet(Element))initWithObjects:(Element Ptr )firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TMutableOrderedSet(Element))initWithObjects:(const Element Ptr  __autoreleasing [])objects count:(NSUInteger)count; \
- (TMutableOrderedSet(Element))initWithOrderedSet:(TOrderedSet(Element))set; \
- (TMutableOrderedSet(Element))initWithOrderedSet:(TOrderedSet(Element))set copyItems:(BOOL)flag; \
- (TMutableOrderedSet(Element))initWithOrderedSet:(TOrderedSet(Element))set range:(NSRange)range copyItems:(BOOL)flag; \
- (TMutableOrderedSet(Element))initWithSet:(TSet(Element))set; \
- (TMutableOrderedSet(Element))initWithSet:(TSet(Element))set copyItems:(BOOL)flag; \
- (TMutableOrderedSet(Element))init; \
- (TMutableOrderedSet(Element))initWithCoder:(NSCoder *)aDecoder; \
- (TMutableOrderedSet(Element))initWithCapacity:(NSUInteger)capacity; \
/*! Adding Objects */ \
- (void)addObject:(Element Ptr )object; \
- (void)addObjects:(const Element Ptr  __autoreleasing [])objects count:(NSUInteger)count; \
- (void)addObjectsFromArray:(TArray(Element))array; \
- (void)insertObject:(Element Ptr )object atIndex:(NSUInteger)index; \
- (void)insertObjects:(TArray(Element))objects atIndexes:(NSIndexSet *)indexes; \
- (void)unionOrderedSet:(TOrderedSet(Element))other; \
- (void)unionSet:(TSet(Element))other; \
/*! Removing Objects */ \
- (void)removeObject:(Element Ptr )object; \
- (void)removeObjectAtIndex:(NSUInteger)idx; \
- (void)removeObjectsAtIndexes:(NSIndexSet *)indexes; \
- (void)removeObjectsInArray:(TArray(Element))array; \
- (void)removeObjectsInRange:(NSRange)range; \
- (void)removeAllObjects; \
- (void)filterUsingPredicate:(NSPredicate *)predicate; \
- (void)intersectOrderedSet:(TOrderedSet(Element))other; \
- (void)minusOrderedSet:(TOrderedSet(Element))other; \
- (void)intersectSet:(TSet(Element))other; \
- (void)minusSet:(TSet(Element))other; \
/*! Replacing Objects */ \
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(Element Ptr )object; \
- (void)replaceObjectsAtIndexes:(NSIndexSet *)indexes withObjects:(TArray(Element))objects; \
- (void)replaceObjectsInRange:(NSRange)range withObjects:(const Element Ptr  __autoreleasing [])objects count:(NSUInteger)count; \
- (void)setObject:(Element Ptr )object atIndex:(NSUInteger)index; \
- (void)setObject:(Element Ptr )obj atIndexedSubscript:(NSUInteger)index; \
/*! Rearranging Content */ \
- (void)moveObjectsAtIndexes:(NSIndexSet *)indexes toIndex:(NSUInteger)index; \
- (void)exchangeObjectAtIndex:(NSUInteger)index withObjectAtIndex:(NSUInteger)index; \
- (void)sortUsingDescriptors:(TArray(NSSortDescriptor))sortDescriptors; \
- (void)sortUsingComparator:(TComparator_##Element)comparator; \
- (void)sortWithOptions:(NSSortOptions)options usingComparator:(TComparator_##Element)comparator; \
- (void)sortRange:(NSRange)range options:(NSSortOptions)options usingComparator:(TComparator_##Element)comparator; \
@end


