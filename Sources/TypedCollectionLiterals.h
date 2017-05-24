//
//  TypedCollectionLiterals.h
//  Typed
//
//  Created by Martin Kiss on 24 May 2017.
//  https://github.com/Tricertops/Typed
//
//  The MIT License (MIT)
//  Copyright © 2017 Martin Kiss
//



//! These macros are much better alternative for built-in @[…] literal, because they infer type of the collection from the objects.
//! In addition, they report compilation error when types of all arguments are not the same.



#define NSArray(first, other...) \
    ( (NSArray<typeof(first)> *) ({ \
        typeof(first) _objects[] = {first, other}; \
        NSUInteger _count = sizeof(_objects) / sizeof(id); \
        [NSArray arrayWithObjects:_objects count:_count]; \
    }) )



#define NSMutableArray(first, other...) \
    ( (NSMutableArray<typeof(first)> *) ({ \
        typeof(first) _objects[] = {first, other}; \
        NSUInteger _count = sizeof(_objects) / sizeof(id); \
        [NSMutableArray arrayWithObjects:_objects count:_count]; \
    }) )


#define NSSet(first, other...) \
    ( (NSSet<typeof(first)> *) ({ \
        typeof(first) _objects[] = {first, other}; \
        NSUInteger _count = sizeof(_objects) / sizeof(id); \
        [NSSet setWithObjects:_objects count:_count]; \
    }) )



#define NSMutableSet(first, other...) \
    ( (NSMutableSet<typeof(first)> *) ({ \
        typeof(first) _objects[] = {first, other}; \
        NSUInteger _count = sizeof(_objects) / sizeof(id); \
        [NSMutableSet setWithObjects:_objects count:_count]; \
    }) )


