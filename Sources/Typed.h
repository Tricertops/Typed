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
//TODO: TDictionary
//TODO: TCache

//TODO: TPointerArray (Strong or Weak)
//TODO: THashTable (Strong or Weak)
//TODO: TMapTable (Strong or Weak Keys, Strong or Weak Values)



TGenerate(NSObject) // Used by TArrayGenerate itself.
TGenerate(NSString) // Used by TArrayGenerate itself.
TGenerate(NSSortDescriptor) // Used by TArrayGenerate itself.
TGenerate(NSDate)
TGenerate(NSNumber)
TGenerate(NSURL)


