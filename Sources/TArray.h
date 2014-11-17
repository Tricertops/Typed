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
_TDictionaryForward(NSString, NSObject)



#define _TArrayCreateProtocol(Element, Ptr) \
/*! Types */ \
typedef BOOL (^TIndexedPredicate_##Element)(Element Ptr object, NSUInteger index, BOOL *stop); \
typedef NSComparisonResult (^TComparator_##Element)(Element Ptr object1, Element Ptr object2); \
typedef void (^TIndexedEnumerator_##Element)(Element Ptr object, NSUInteger index, BOOL *stop); \
typedef NSInteger (*TSortFunction_##Element)(Element Ptr , Element Ptr , void *); \
_TMutableArrayForward(Element) \
/*! NSArray Interface */ \
_TArrayForward(Element) \
@protocol TArray_##Element <_TProtocols> \
- (TArray(Element))self; \
- (Element Ptr)T_Element; \
- (Element Ptr)T_Enumeration; \
/*! Initializing an Array */ \
- (TArray(Element))init; \
- (TArray(Element))initWithArray:(TArray(Element))array; \
- (TArray(Element))initWithArray:(TArray(Element))array copyItems:(BOOL)flag; \
- (TArray(Element))initWithContentsOfFile:(NSString *)path; \
- (TArray(Element))initWithContentsOfURL:(NSURL *)URL; \
- (TArray(Element))initWithObjects:(Element Ptr )firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TArray(Element))initWithObjects:(const Element Ptr  __autoreleasing [])objects count:(NSUInteger)count; \
- (TArray(Element))initWithCoder:(NSCoder *)decoder; \
/*! Querying an Array */ \
- (BOOL)containsObject:(Element Ptr )object; \
@property (readonly) NSUInteger count; \
- (void)getObjects:(Element Ptr  __unsafe_unretained [])objects range:(NSRange)range; \
@property (nonatomic, readonly) Element Ptr firstObject; \
@property (nonatomic, readonly) Element Ptr lastObject; \
- (Element Ptr )objectAtIndex:(NSUInteger)index; \
- (Element Ptr )objectAtIndexedSubscript:(NSUInteger)index; \
- (TArray(Element))objectsAtIndexes:(NSIndexSet *)indexes; \
- (NSEnumerator *)objectEnumerator; \
- (NSEnumerator *)reverseObjectEnumerator; \
/*! Finding Objects in an Array */ \
- (NSUInteger)indexOfObject:(Element Ptr )object; \
- (NSUInteger)indexOfObject:(Element Ptr )object inRange:(NSRange)range; \
- (NSUInteger)indexOfObject:(Element Ptr )object inSortedRange:(NSRange)range options:(NSBinarySearchingOptions)options usingComparator:(TComparator_##Element)cmp; \
- (NSUInteger)indexOfObjectIdenticalTo:(Element Ptr )object; \
- (NSUInteger)indexOfObjectIdenticalTo:(Element Ptr )object inRange:(NSRange)range; \
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
/*! Comparing Arrays */ \
- (Element Ptr )firstObjectCommonWithArray:(TArray(Element))other; \
- (BOOL)isEqual:(TArray(Element))other; \
- (BOOL)isEqualToArray:(TArray(Element))other; \
/*! Copying an Array */ \
- (TArray(Element))copy; \
- (TArray(Element))copyWithZone:(NSZone *)zone; \
- (TMutableArray(Element))mutableCopy; \
- (TMutableArray(Element))mutableCopyWithZone:(NSZone *)zone; \
/*! Deriving New Arrays */ \
- (TArray(Element))arrayByAddingObject:(Element Ptr )object; \
- (TArray(Element))arrayByAddingObjectsFromArray:(TArray(Element))other; \
- (TArray(Element))filteredArrayUsingPredicate:(NSPredicate *)predicate; \
- (TArray(Element))subarrayWithRange:(NSRange)range; \
/*! Sorting an Array */ \
@property (readonly, copy) NSData *sortedArrayHint; \
- (TArray(Element))sortedArrayUsingFunction:(TSortFunction_##Element)comparator context:(void *)context; \
- (TArray(Element))sortedArrayUsingFunction:(TSortFunction_##Element)comparator context:(void *)context hint:(NSData *)hint; \
- (TArray(Element))sortedArrayUsingDescriptors:(TArray(NSSortDescriptor))sortDescriptors; \
- (TArray(Element))sortedArrayUsingSelector:(SEL)comparator; \
- (TArray(Element))sortedArrayUsingComparator:(TComparator_##Element)comparator; \
- (TArray(Element))sortedArrayWithOptions:(NSSortOptions)options usingComparator:(TComparator_##Element)comparator; \
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
- (TDictionary(NSString, NSObject))dictionaryWithValuesForKeys:(TArray(NSString))keys; \
- (void)setValuesForKeysWithDictionary:(TDictionary(NSString, NSObject))keyedValues; \
@end \


