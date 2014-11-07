//
//  TOrderedSet.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TCollections.h"



_TArrayForward(NSString)
_TArrayForward(NSSortDescriptor)
_TDictionaryForward(NSString, NSObject)



#define _TOrderedSetCreateProtocol(Element, Ptr) \
/*! Types */ \
typedef BOOL (^TIndexedPredicate_##Element)(Element Ptr object, NSUInteger index, BOOL *stop); \
typedef void (^TIndexedEnumerator_##Element)(Element Ptr object, NSUInteger index, BOOL *stop); \
typedef NSComparisonResult (^TComparator_##Element)(Element Ptr object1, Element Ptr object2); \
_TArrayForward(Element) \
_TSetForward(Element) \
_TMutableOrderedSetForward(Element) \
/*! NSOrderedSet Interface */ \
_TOrderedSetForward(Element) \
@protocol TOrderedSet_##Element <_TProtocols> \
- (TOrderedSet(Element))self; \
/*! Initializing an Ordered Set */ \
- (TOrderedSet(Element))initWithArray:(TArray(Element))array; \
- (TOrderedSet(Element))initWithArray:(TArray(Element))set copyItems:(BOOL)flag; \
- (TOrderedSet(Element))initWithArray:(TArray(Element))set range:(NSRange)range copyItems:(BOOL)flag; \
- (TOrderedSet(Element))initWithObject:(Element Ptr )object; \
- (TOrderedSet(Element))initWithObjects:(Element Ptr )firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TOrderedSet(Element))initWithObjects:(const Element Ptr  __autoreleasing [])objects count:(NSUInteger)count; \
- (TOrderedSet(Element))initWithOrderedSet:(TOrderedSet(Element))set; \
- (TOrderedSet(Element))initWithOrderedSet:(TOrderedSet(Element))set copyItems:(BOOL)flag; \
- (TOrderedSet(Element))initWithOrderedSet:(TOrderedSet(Element))set range:(NSRange)range copyItems:(BOOL)flag; \
- (TOrderedSet(Element))initWithSet:(TSet(Element))set; \
- (TOrderedSet(Element))initWithSet:(TSet(Element))set copyItems:(BOOL)flag; \
- (TOrderedSet(Element))init; \
- (TOrderedSet(Element))initWithCoder:(NSCoder *)aDecoder; \
/*! Querying an Ordered Set */ \
@property (readonly) NSUInteger count; \
- (Element Ptr )objectAtIndex:(NSUInteger)index; \
- (BOOL)containsObject:(Element Ptr )object; \
@property (nonatomic, readonly) Element Ptr firstObject; \
@property (nonatomic, readonly) Element Ptr lastObject; \
- (void)getObjects:(Element Ptr  __unsafe_unretained [])objects range:(NSRange)range; \
- (Element Ptr )objectAtIndexedSubscript:(NSUInteger)index; \
- (TArray(Element))objectsAtIndexes:(NSIndexSet *)indexes; \
- (NSEnumerator *)objectEnumerator; \
- (NSEnumerator *)reverseObjectEnumerator; \
@property(readonly, copy) TOrderedSet(Element) reversedOrderedSet; \
/*! Finding Objects in an Ordered Set */ \
- (NSUInteger)indexOfObject:(Element Ptr )object; \
- (NSUInteger)indexOfObject:(Element Ptr )object inSortedRange:(NSRange)range options:(NSBinarySearchingOptions)options usingComparator:(TComparator_##Element)cmp; \
- (NSUInteger)indexOfObjectPassingTest:(TIndexedPredicate_##Element)predicate; \
- (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)options passingTest:(TIndexedPredicate_##Element)predicate; \
- (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet *)indexes options:(NSEnumerationOptions)options passingTest:(TIndexedPredicate_##Element)predicate; \
- (NSIndexSet *)indexesOfObjectsPassingTest:(TIndexedPredicate_##Element)predicate; \
- (NSIndexSet *)indexesOfObjectsWithOptions:(NSEnumerationOptions)options passingTest:(TIndexedPredicate_##Element)predicate; \
- (NSIndexSet *)indexesOfObjectsAtIndexes:(NSIndexSet *)indexes options:(NSEnumerationOptions)options passingTest:(TIndexedPredicate_##Element)predicate; \
/*! Sending Messages to Elements */ \
- (void)makeObjectsPerformSelector:(SEL)aSelector; \
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument; \
- (void)enumerateObjectsUsingBlock:(TIndexedEnumerator_##Element)block; \
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)options usingBlock:(TIndexedEnumerator_##Element)block; \
- (void)enumerateObjectsAtIndexes:(NSIndexSet *)indexes options:(NSEnumerationOptions)options usingBlock:(TIndexedEnumerator_##Element)block; \
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
- (TMutableOrderedSet(Element))mutableCopy; \
- (TMutableOrderedSet(Element))mutableCopyWithZone:(NSZone *)zone; \
/*! Deriving New Collections */ \
- (TOrderedSet(Element))filteredOrderedSetUsingPredicate:(NSPredicate *)predicate; \
- (TArray(Element))sortedArrayUsingDescriptors:(TArray(NSSortDescriptor))sortDescriptors; \
- (TArray(Element))sortedArrayUsingComparator:(TComparator_##Element)comparator; \
- (TArray(Element))sortedArrayWithOptions:(NSSortOptions)options usingComparator:(TComparator_##Element)comparator; \
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
- (TDictionary(NSString, NSObject))dictionaryWithValuesForKeys:(TArray(NSString))keys; \
- (void)setValuesForKeysWithDictionary:(TDictionary(NSString, NSObject))keyedValues; \
@end


