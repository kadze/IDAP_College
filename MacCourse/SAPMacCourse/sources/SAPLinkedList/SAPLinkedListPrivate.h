//
//  SAPLinkedListPrivate.h
//  MacCourse
//
//  Created by S A P on 11/6/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef SAPLinkedListPrivate_h
#define SAPLinkedListPrivate_h

typedef struct SAPLinkedList SAPLinkedList;

extern
void SAPLinkedListSetMutationsCount(SAPLinkedList *list, uint64_t count);

extern
uint64_t SAPLinkedListMutationsCount(SAPLinkedList *list);

#endif /* SAPLinkedListPrivate_h */
