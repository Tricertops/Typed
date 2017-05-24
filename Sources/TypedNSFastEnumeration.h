//
//  TypedNSFastEnumeration.h
//  Typed
//
//  Created by Martin Kiss on 24 May 2017.
//  https://github.com/Tricertops/Typed
//
//  The MIT License (MIT)
//  Copyright © 2017 Martin Kiss
//



//! Formalized method for type inference. All classes that conform to NSFastEnumeration should be extended with this protocol.
//! The method doesn’t need implementation, since it’s only used for typeof(…) compiler feature in foreach(…) macro.
@protocol TypedNSFastEnumeration <NSFastEnumeration>

- (id)Typed_enumeratedType;

@end



@interface NSArray<ElementType> (TypedNSFastEnumeration) <TypedNSFastEnumeration>

- (ElementType)Typed_enumeratedType;

@end



@interface NSSet<ElementType> (TypedNSFastEnumeration) <TypedNSFastEnumeration>

- (ElementType)Typed_enumeratedType;

@end



@interface NSOrderedSet<ElementType> (TypedNSFastEnumeration) <TypedNSFastEnumeration>

- (ElementType)Typed_enumeratedType;

@end



@interface NSPointerArray (TypedNSFastEnumeration) <TypedNSFastEnumeration>

- (void *)Typed_enumeratedType;

@end



@interface NSHashTable<ElementType> (TypedNSFastEnumeration) <TypedNSFastEnumeration>

- (ElementType)Typed_enumeratedType;

@end



@interface NSDictionary<KeyType, ValueType> (TypedNSFastEnumeration) <TypedNSFastEnumeration>

- (KeyType)Typed_enumeratedType;

@end



@interface NSMapTable<KeyType, ValueType> (TypedNSFastEnumeration) <TypedNSFastEnumeration>

- (KeyType)Typed_enumeratedType;

@end



@interface NSEnumerator<ElementType> (TypedNSFastEnumeration) <TypedNSFastEnumeration>

- (ElementType)Typed_enumeratedType;

@end




