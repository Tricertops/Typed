//
//  TSet.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TDeclarations.h"



#define _TSetCreateProtocol(Element) \
/*! Types */ \
@class Element; \
typedef void (^TSetEnumerator_##Element)(Element *object, BOOL *stop); \
typedef BOOL (^TSetPredicate_##Element)(Element *object, BOOL *stop); \
_TArrayForward(Element) \
_TMutableSetForward(Element) \
/*! NSSet Interface */ \
@protocol TSet_##Element <_TProtocols> \
/*! Initializing a Set */ \
- (TSet(Element))initWithArray:(TArray(Element))array; \
- (TSet(Element))initWithObjects:(Element *)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TSet(Element))initWithObjects:(const Element * __autoreleasing [])objects count:(NSUInteger)count; \
- (TSet(Element))initWithSet:(TSet(Element))set; \
- (TSet(Element))initWithSet:(TSet(Element))set copyItems:(BOOL)flag; \
- (TSet(Element))init; \
- (TSet(Element))initWithCoder:(NSCoder *)decoder; \
/*! Querying a Set */ \
@property (readonly) NSUInteger count; \
@property (readonly, copy) TArray(Element) allObjects; \
- (Element *)anyObject; \
- (BOOL)containsObject:(Element *)object; \
- (Element *)member:(Element *)object; \
- (NSEnumerator *)objectEnumerator; \
/*! Sending Messages to Elements */ \
- (void)makeObjectsPerformSelector:(SEL)aSelector; \
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument; \
- (void)enumerateObjectsUsingBlock:(TSetEnumerator_##Element)block; \
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)options usingBlock:(TSetEnumerator_##Element)block; \
/*! Comparing Sets */ \
- (BOOL)isEqual:(TSet(Element))otherSet; \
- (BOOL)isEqualToSet:(TSet(Element))otherSet; \
- (BOOL)isSubsetOfSet:(TSet(Element))otherSet; \
- (BOOL)intersectsSet:(TSet(Element))otherSet; \
/*! Copying a Set */ \
- (TSet(Element))copy; \
- (TSet(Element))copyWithZone:(NSZone *)zone; \
- (TMutableSet(Element))mutableCopy; \
- (TMutableSet(Element))mutableCopyWithZone:(NSZone *)zone; \
/*! Deriving New Sets */ \
- (TSet(Element))setByAddingObject:(Element *)object; \
- (TSet(Element))setByAddingObjectsFromSet:(TSet(Element))otherSet; \
- (TSet(Element))setByAddingObjectsFromArray:(TArray(Element))array; \
- (TSet(Element))filteredSetUsingPredicate:(NSPredicate *)predicate; \
- (TSet(Element))objectsPassingTest:(BOOL (^)(id obj, BOOL *stop))predicate; \
- (TSet(Element))objectsWithOptions:(NSEnumerationOptions)options passingTest:(TSetPredicate_##Element)predicate; \
/*! Creating a Sorted Array */ \
- (TArray(Element))sortedArrayUsingDescriptors:(TArray(NSSortDescriptor))sortDescriptors; \
/*! Creating a Description */ \
@property (readonly, copy) NSString *description; \
- (NSString *)descriptionWithLocale:(id)locale; \
/*! Key-Value Coding */ \
- (id)valueForKey:(NSString *)key; \
- (void)setValue:(id)value forKey:(NSString *)key; \
- (id)valueForKeyPath:(NSString *)keyPath; \
- (void)setValue:(id)value forKeyPath:(NSString *)keyPath; \
- (NSDictionary *)dictionaryWithValuesForKeys:(TArray(NSString) *)keys; \
- (void)setValuesForKeysWithDictionary:(NSDictionary *)keyedValues; \
@end


