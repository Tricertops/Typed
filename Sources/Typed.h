//
//  Typed.h
//  Typed
//
//  Created by Martin Kiss on 24 May 2017.
//  https://github.com/Tricertops/Typed
//
//  The MIT License (MIT)
//  Copyright © 2017 Martin Kiss
//

@import Foundation;



//! Swift-like macro for type inferrence of local or global variables.
#define var  __auto_type


//! Swift-like macro for type inferrence of local or global variables that cannot be re-assigned.
#define let  __auto_type const


//! Macro that expands to for-in loop with inferred type of enumerated variable.
#define foreach(element, collection) \
    for (typeof((collection).Typed_enumeratedType) element in (collection))

#import "TypedNSFastEnumeration.h"


//! Type inferrence for -copy and -mutableCopy methods.
#import "TypedNSCopying.h"


//! Type-checked collection literals as a replacement for built-in @[…].
#import "TypedCollectionLiterals.h"


