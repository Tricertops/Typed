//
//  TMutableArray.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TArray.h"



#define _TMutableArrayCreateProtocol(Element, Ptr) \
/*! NSMutableArray Interface */ \
_TMutableArrayForward(Element) \
@protocol TMutableArray_##Element <TArray_##Element> \
- (TMutableArray(Element))self; \
- (NSMutableArray *)untyped; \
/*! Initializing an Array */ \
- (TMutableArray(Element))init; \
- (TMutableArray(Element))initWithArray:(TArray(Element))array; \
- (TMutableArray(Element))initWithArray:(TArray(Element))array copyItems:(BOOL)flag; \
- (TMutableArray(Element))initWithContentsOfFile:(NSString *)path; \
- (TMutableArray(Element))initWithContentsOfURL:(NSURL *)URL; \
- (TMutableArray(Element))initWithObjects:(Element Ptr )firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TMutableArray(Element))initWithObjects:(const Element Ptr  __autoreleasing [])objects count:(NSUInteger)count; \
- (TMutableArray(Element))initWithCoder:(NSCoder *)decoder; \
/*! Adding Objects */ \
- (void)addObject:(Element Ptr )object; \
- (void)addObjectsFromArray:(TArray(Element))other; \
- (void)insertObject:(Element Ptr )object atIndex:(NSUInteger)index; \
- (void)insertObjects:(TArray(Element))objects atIndexes:(NSIndexSet *)indexes; \
/*! Removing Objects */ \
- (void)removeAllObjects; \
- (void)removeLastObject; \
- (void)removeObject:(Element Ptr )object; \
- (void)removeObject:(Element Ptr )object inRange:(NSRange)range; \
- (void)removeObjectAtIndex:(NSUInteger)index; \
- (void)removeObjectsAtIndexes:(NSIndexSet *)indexes; \
- (void)removeObjectIdenticalTo:(Element Ptr )object; \
- (void)removeObjectIdenticalTo:(Element Ptr )object inRange:(NSRange)range; \
- (void)removeObjectsInArray:(TArray(Element))other; \
- (void)removeObjectsInRange:(NSRange)range; \
/*! Replacing Objects */ \
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(Element Ptr )object; \
- (void)setObject:(Element Ptr )object atIndexedSubscript:(NSUInteger)index; \
- (void)replaceObjectsAtIndexes:(NSIndexSet *)indexes withObjects:(TArray(Element))objects; \
- (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(TArray(Element))other range:(NSRange)otherRange; \
- (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(TArray(Element))other; \
- (void)setArray:(TArray(Element))other; \
/*! Filtering Array */ \
- (void)filterUsingPredicate:(NSPredicate *)predicate; \
/*! Rearranging Content */ \
- (void)exchangeObjectAtIndex:(NSUInteger)index1 withObjectAtIndex:(NSUInteger)index2; \
- (void)sortUsingDescriptors:(TArray(NSSortDescriptor))sortDescriptors; \
- (void)sortUsingComparator:(TComparator_##Element)comparator; \
- (void)sortWithOptions:(NSSortOptions)options usingComparator:(TComparator_##Element)comparator; \
- (void)sortUsingFunction:(TSortFunction_##Element)compare context:(void *)context; \
- (void)sortUsingSelector:(SEL)comparator; \
/*! Extension: Random */ \
@property (readonly) NSUInteger randomInsertionIndex; \
- (void)randomizeObjects; \
@end


