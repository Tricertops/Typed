//
//  TArray.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TCollections.h"



_TArrayForward(NSString)
_TArrayForward(NSSortDescriptor)



#define _TArrayCreateProtocol(Element) \
/*! Types */ \
@class Element; \
typedef BOOL (^TArrayPredicate_##Element)(Element *object, NSUInteger index, BOOL *stop); \
typedef NSComparisonResult (^TArrayComparator_##Element)(Element *object1, Element *object2); \
typedef void (^TArrayEnumerator_##Element)(Element *object, NSUInteger index, BOOL *stop); \
typedef NSInteger (*TArraySortFunction_##Element)(Element *, Element *, void *); \
_TMutableArrayForward(Element) \
/*! NSArray Interface */ \
@protocol TArray_##Element <_TProtocols> \
/*! Initializing an Array */ \
- (TArray(Element))init; \
- (TArray(Element))initWithArray:(TArray(Element))array; \
- (TArray(Element))initWithArray:(TArray(Element))array copyItems:(BOOL)flag; \
- (TArray(Element))initWithContentsOfFile:(NSString *)path; \
- (TArray(Element))initWithContentsOfURL:(NSURL *)URL; \
- (TArray(Element))initWithObjects:(Element *)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TArray(Element))initWithObjects:(const Element * __autoreleasing [])objects count:(NSUInteger)count; \
- (TArray(Element))initWithCoder:(NSCoder *)decoder; \
/*! Querying an Array */ \
- (BOOL)containsObject:(Element *)object; \
@property (readonly) NSUInteger count; \
- (void)getObjects:(Element * __unsafe_unretained [])objects range:(NSRange)range; \
@property (nonatomic, readonly) Element *firstObject; \
@property (nonatomic, readonly) Element *lastObject; \
- (Element *)objectAtIndex:(NSUInteger)index; \
- (Element *)objectAtIndexedSubscript:(NSUInteger)index; \
- (TArray(Element))objectsAtIndexes:(NSIndexSet *)indexes; \
- (NSEnumerator *)objectEnumerator; \
- (NSEnumerator *)reverseObjectEnumerator; \
/*! Finding Objects in an Array */ \
- (NSUInteger)indexOfObject:(Element *)object; \
- (NSUInteger)indexOfObject:(Element *)object inRange:(NSRange)range; \
- (NSUInteger)indexOfObject:(Element *)object inSortedRange:(NSRange)range options:(NSBinarySearchingOptions)options usingComparator:(TArrayComparator_##Element)cmp; \
- (NSUInteger)indexOfObjectIdenticalTo:(Element *)object; \
- (NSUInteger)indexOfObjectIdenticalTo:(Element *)object inRange:(NSRange)range; \
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
/*! Comparing Arrays */ \
- (Element *)firstObjectCommonWithArray:(TArray(Element))otherArray; \
- (BOOL)isEqual:(TArray(Element))otherArray; \
- (BOOL)isEqualToArray:(TArray(Element))otherArray; \
/*! Copying an Array */ \
- (TArray(Element))copy; \
- (TArray(Element))copyWithZone:(NSZone *)zone; \
- (TMutableArray(Element))mutableCopy; \
- (TMutableArray(Element))mutableCopyWithZone:(NSZone *)zone; \
/*! Deriving New Arrays */ \
- (TArray(Element))self; \
- (TArray(Element))arrayByAddingObject:(Element *)object; \
- (TArray(Element))arrayByAddingObjectsFromArray:(TArray(Element))otherArray; \
- (TArray(Element))filteredArrayUsingPredicate:(NSPredicate *)predicate; \
- (TArray(Element))subarrayWithRange:(NSRange)range; \
/*! Sorting an Array */ \
@property (readonly, copy) NSData *sortedArrayHint; \
- (TArray(Element))sortedArrayUsingFunction:(TArraySortFunction_##Element)comparator context:(void *)context; \
- (TArray(Element))sortedArrayUsingFunction:(TArraySortFunction_##Element)comparator context:(void *)context hint:(NSData *)hint; \
- (TArray(Element))sortedArrayUsingDescriptors:(TArray(NSSortDescriptor))sortDescriptors; \
- (TArray(Element))sortedArrayUsingSelector:(SEL)comparator; \
- (TArray(Element))sortedArrayUsingComparator:(TArrayComparator_##Element)comparator; \
- (TArray(Element))sortedArrayWithOptions:(NSSortOptions)options usingComparator:(TArrayComparator_##Element)comparator; \
/*! Working With String Elements */ \
- (NSString *)componentsJoinedByString:(NSString *)separator; \
/*! Creating a Description */ \
@property (readonly, copy) NSString *description; \
- (NSString *)descriptionWithLocale:(id)locale; \
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level; \
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile; \
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically; \
/*! Collecting Paths */ \
- (TArray(NSString))pathsMatchingExtensions:(NSArray *)filterTypes; \
/*! Key-Value Observing */ \
- (void)addObserver:(NSObject *)observer toObjectsAtIndexes:(NSIndexSet *)indexes forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(void *)context; \
- (void)removeObserver:(NSObject *)observer fromObjectsAtIndexes:(NSIndexSet *)indexes forKeyPath:(NSString *)keyPath context:(void *)context; \
- (void)removeObserver:(NSObject *)observer fromObjectsAtIndexes:(NSIndexSet *)indexes forKeyPath:(NSString *)keyPath; \
/*! Key-Value Coding */ \
- (id)valueForKey:(NSString *)key; \
- (void)setValue:(id)value forKey:(NSString *)key; \
- (id)valueForKeyPath:(NSString *)keyPath; \
- (void)setValue:(id)value forKeyPath:(NSString *)keyPath; \
- (NSDictionary *)dictionaryWithValuesForKeys:(TArray(NSString) *)keys; \
- (void)setValuesForKeysWithDictionary:(NSDictionary *)keyedValues; \
@end \


