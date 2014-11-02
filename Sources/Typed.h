//
//  Typed.h
//  Typed
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

//TODO: Prevet importing multiple times.
#import "TDeclarations.h"

#import "TMutableArray.h"
#import "TMutableSet.h"
#import "TOrderedSet.h"
//TODO: TMutableOrderedSet
//TODO: TDictionary
//TODO: TCache

//TODO: TWeakArray as weakObjectsPointerArray
//TODO: TWeakSet as weakObjectsHashTable
//TODO: TWeakKeysDictionary as weakToStrongObjectsMapTable
//TODO: TWeakValuesDictionary as strongToWeakObjectsMapTable
//TODO: TWeakDictionary as weakToWeakObjectsMapTable



TGenerate(NSString) // Used by TArrayGenerate itself.
TGenerate(NSSortDescriptor) // Used by TArrayGenerate itself.
TGenerate(NSDate)
TGenerate(NSNumber)
TGenerate(NSURL)


