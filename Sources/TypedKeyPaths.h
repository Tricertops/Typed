//
//  TypedKeyPaths.h
//  Typed
//
//  Created by Martin Kiss on 14 June 2017.
//  https://github.com/Tricertops/Typed
//
//  The MIT License (MIT)
//  Copyright © 2017 Martin Kiss
//



//! Macro for building type-checked keypath strings. Prefix usage with @ symbol. Works with instances and classes.
#define keypath(receiver, keypath) \
    ( ((void)(NO && ((void)receiver.Typed_keypath.keypath, NO)), #keypath) )



//! This extends both instances and classes with unified method that returns instancetype for use in @keypath(…) macro.
@interface NSObject (TypedKeyPaths)

+ (instancetype)Typed_keypath;
- (instancetype)Typed_keypath;

@end


