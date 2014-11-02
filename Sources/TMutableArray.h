//
//  TMutableArray.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TArray.h"



#define _TMutableArrayCreateProtocol(Element) \
@class Element; \
/*! NSMutableArray Interface */ \
@protocol TMutableArray_##Element <TArray_##Element> \
/*! Initializing an Array */ \
- (TMutableArray(Element))init; \
- (TMutableArray(Element))initWithArray:(TArray(Element))array; \
- (TMutableArray(Element))initWithArray:(TArray(Element))array copyItems:(BOOL)flag; \
- (TMutableArray(Element))initWithContentsOfFile:(NSString *)path; \
- (TMutableArray(Element))initWithContentsOfURL:(NSURL *)URL; \
- (TMutableArray(Element))initWithObjects:(Element *)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TMutableArray(Element))initWithObjects:(const Element * __autoreleasing [])objects count:(NSUInteger)count; \
- (TMutableArray(Element))initWithCoder:(NSCoder *)decoder; \
/*! Adding Objects */ \
- (void)addObject:(Element *)object; \
- (void)addObjectsFromArray:(TArray(Element))otherArray; \
- (void)insertObject:(Element *)object atIndex:(NSUInteger)index; \
- (void)insertObjects:(TArray(Element))objects atIndexes:(NSIndexSet *)indexes; \
/*! Removing Objects */ \
- (void)removeAllObjects; \
- (void)removeLastObject; \
- (void)removeObject:(Element *)object; \
- (void)removeObject:(Element *)object inRange:(NSRange)range; \
- (void)removeObjectAtIndex:(NSUInteger)index; \
- (void)removeObjectsAtIndexes:(NSIndexSet *)indexes; \
- (void)removeObjectIdenticalTo:(Element *)object; \
- (void)removeObjectIdenticalTo:(Element *)object inRange:(NSRange)range; \
- (void)removeObjectsInArray:(TArray(Element))otherArray; \
- (void)removeObjectsInRange:(NSRange)range; \
/*! Replacing Objects */ \
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(Element *)object; \
- (void)setObject:(Element *)object atIndexedSubscript:(NSUInteger)index; \
- (void)replaceObjectsAtIndexes:(NSIndexSet *)indexes withObjects:(TArray(Element))objects; \
- (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(TArray(Element))otherArray range:(NSRange)otherRange; \
- (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(TArray(Element))otherArray; \
- (void)setArray:(TArray(Element))otherArray; \
/*! Filtering Array */ \
- (void)filterUsingPredicate:(NSPredicate *)predicate; \
/*! Rearranging Content */ \
- (void)exchangeObjectAtIndex:(NSUInteger)index1 withObjectAtIndex:(NSUInteger)index2; \
- (void)sortUsingDescriptors:(TArray(NSSortDescriptor))sortDescriptors; \
- (void)sortUsingComparator:(TArrayComparator_##Element)comparator; \
- (void)sortWithOptions:(NSSortOptions)options usingComparator:(TArrayComparator_##Element)comparator; \
- (void)sortUsingFunction:(TArraySortFunction_##Element)compare context:(void *)context; \
- (void)sortUsingSelector:(SEL)comparator; \
@end


