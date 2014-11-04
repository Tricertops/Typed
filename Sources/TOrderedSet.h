//
//  TOrderedSet.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TCollections.h"



#define _TOrderedSetCreateProtocol(Element) \
/*! Types */ \
@class Element; \
_TArrayForward(Element) \
_TSetForward(Element) \
/*! NSOrderedSet Interface */ \
@protocol TOrderedSet_##Element <_TProtocols> \
/*! Initializing an Ordered Set */ \
- (TOrderedSet(Element))initWithArray:(TArray(Element))array; \
- (TOrderedSet(Element))initWithArray:(TArray(Element))set copyItems:(BOOL)flag; \
- (TOrderedSet(Element))initWithArray:(TArray(Element))set range:(NSRange)range copyItems:(BOOL)flag; \
- (TOrderedSet(Element))initWithObject:(Element *)object; \
- (TOrderedSet(Element))initWithObjects:(Element *)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TOrderedSet(Element))initWithObjects:(const Element * __autoreleasing [])objects count:(NSUInteger)count; \
- (TOrderedSet(Element))initWithOrderedSet:(TOrderedSet(Element))set; \
- (TOrderedSet(Element))initWithOrderedSet:(TOrderedSet(Element))set copyItems:(BOOL)flag; \
- (TOrderedSet(Element))initWithOrderedSet:(TOrderedSet(Element))set range:(NSRange)range copyItems:(BOOL)flag; \
- (TOrderedSet(Element))initWithSet:(TSet(Element))set; \
- (TOrderedSet(Element))initWithSet:(TSet(Element))set copyItems:(BOOL)flag; \
- (TOrderedSet(Element))init; \
- (TOrderedSet(Element))initWithCoder:(NSCoder *)aDecoder; \
/*! Querying an Ordered Set */ \
@property (readonly) NSUInteger count; \
- (Element *)objectAtIndex:(NSUInteger)index; \
- (BOOL)containsObject:(Element *)object; \
@property (nonatomic, readonly) Element *firstObject; \
@property (nonatomic, readonly) Element *lastObject; \
- (void)getObjects:(Element * __unsafe_unretained [])objects range:(NSRange)range; \
- (Element *)objectAtIndexedSubscript:(NSUInteger)index; \
- (TArray(Element))objectsAtIndexes:(NSIndexSet *)indexes; \
- (NSEnumerator *)objectEnumerator; \
- (NSEnumerator *)reverseObjectEnumerator; \
@property(readonly, copy) TOrderedSet(Element) reversedOrderedSet; \
/*! Finding Objects in an Ordered Set */ \
- (NSUInteger)indexOfObject:(Element *)object; \
- (NSUInteger)indexOfObject:(Element *)object inSortedRange:(NSRange)range options:(NSBinarySearchingOptions)options usingComparator:(TArrayComparator_##Element)cmp; \
- (NSUInteger)indexOfObjectPassingTest:(TArrayPredicate_##Element)predicate; \
- (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)options passingTest:(TArrayPredicate_##Element)predicate; \
- (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet *)indexes options:(NSEnumerationOptions)options passingTest:(TArrayPredicate_##Element)predicate; \
- (NSIndexSet *)indexesOfObjectsPassingTest:(TArrayPredicate_##Element)predicate; \
- (NSIndexSet *)indexesOfObjectsWithOptions:(NSEnumerationOptions)options passingTest:(TArrayPredicate_##Element)predicate; \
- (NSIndexSet *)indexesOfObjectsAtIndexes:(NSIndexSet *)indexes options:(NSEnumerationOptions)options passingTest:(TArrayPredicate_##Element)predicate; \
/*! Sending Messages to Elements */ \
- (void)makeObjectsPerformSelector:(SEL)aSelector; \
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument; \
- (void)enumerateObjectsUsingBlock:(TArrayEnumerator_##Element)block; \
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)options usingBlock:(TArrayEnumerator_##Element)block; \
- (void)enumerateObjectsAtIndexes:(NSIndexSet *)indexes options:(NSEnumerationOptions)options usingBlock:(TArrayEnumerator_##Element)block; \
/*! Comparing Sets */ \
- (BOOL)isEqual:(TOrderedSet(Element))other; \
- (BOOL)isEqualToOrderedSet:(TOrderedSet(Element))other; \
- (BOOL)isSubsetOfOrderedSet:(TOrderedSet(Element))other; \
- (BOOL)intersectsOrderedSet:(TOrderedSet(Element))other; \
- (BOOL)isSubsetOfSet:(TSet(Element))set; \
- (BOOL)intersectsSet:(TSet(Element))set; \
/*! Copying an Ordered Set */ \
- (TOrderedSet(Element))copy; \
- (TOrderedSet(Element))copyWithZone:(NSZone *)zone; \
- (TOrderedSet(Element))mutableCopy; \
- (TOrderedSet(Element))mutableCopyWithZone:(NSZone *)zone; \
/*! Deriving New Collections */ \
- (TOrderedSet(Element))filteredOrderedSetUsingPredicate:(NSPredicate *)predicate; \
- (TArray(Element))sortedArrayUsingDescriptors:(TArray(NSSortDescriptor))sortDescriptors; \
- (TArray(Element))sortedArrayUsingComparator:(TArrayComparator_##Element)comparator; \
- (TArray(Element))sortedArrayWithOptions:(NSSortOptions)options usingComparator:(TArrayComparator_##Element)comparator; \
/*! Converting to Other Collections */ \
- (TArray(Element))array; \
- (TSet(Element))set; \
/*! Creating a Description */ \
@property (readonly, copy) NSString *description; \
- (NSString *)descriptionWithLocale:(id)locale; \
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level; \
/*! Key-Value Coding */ \
- (id)valueForKey:(NSString *)key; \
- (void)setValue:(id)value forKey:(NSString *)key; \
- (id)valueForKeyPath:(NSString *)keyPath; \
- (void)setValue:(id)value forKeyPath:(NSString *)keyPath; \
- (NSDictionary *)dictionaryWithValuesForKeys:(TArray(NSString) *)keys; \
- (void)setValuesForKeysWithDictionary:(NSDictionary *)keyedValues; \
@end


