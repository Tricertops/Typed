//
//  Typed.h
//  Typed
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TCollections.h"

#import "TMutableArray.h"
#import "TMutableSet.h"
#import "TCountedSet.h"
#import "TMutableOrderedSet.h"
#import "TMutableDictionary.h"
#import "TCache.h"
#import "TWeakSet.h"

//TODO: TPointerArray (Strong or Weak)
//TODO: TMapTable (Strong or Weak Keys, Strong or Weak Values)


//TODO: Extensibility, since categories doesn’t work.
//TODO: Create prepopulated with copies of single object (Array).
//TODO: Map to collection of different type (Array, Set, OrderedSet)
//TODO: Subcollection from/to index (Array, OrderedSet)
//TODO: Add object if non-nil (Array, Set, OrderedSet, Dictionary).

//TODO: Flattened array?
//TODO: Create mapped dictionary?


#pragma mark -

TGenerate(id,)
TAssociativeGenerate(id, , id,)

TGenerate(NSString,*) // Useds for KVC methods.
TGenerate(NSSortDescriptor,*) // Used by sorting methods.
TAssociativeGenerate(NSString,*, NSObject,*) // Useds for KVC methods.


TGenerate(NSObject,*)
TGenerate(NSDate,*)
TGenerate(NSNumber,*)
TGenerate(NSURL,*)

TAssociativeGenerate(NSObject,*, NSObject,*)
TAssociativeGenerate(NSString,*, NSString,*)
TAssociativeGenerate(NSString,*, NSNumber,*)
TAssociativeGenerate(NSNumber,*, NSObject,*)
TAssociativeGenerate(NSNumber,*, NSString,*)
TAssociativeGenerate(NSNumber,*, NSNumber,*)


