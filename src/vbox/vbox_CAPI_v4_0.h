/*
 * Libvirt notice: this file is derived from the VirtualBox SDK, with
 * libvirt edits; do not regenerate in the context of libvirt.
 */
/*
 *  DO NOT EDIT! This is a generated file.
 *
 *  XPCOM IDL (XPIDL) definition for VirtualBox Main API (COM interfaces)
 *  generated from XIDL (XML interface definition).
 *
 *  Source    : src/VBox/Main/idl/VirtualBox.xidl
 *  Generator : src/VBox/Main/idl/xpcidl.xsl
 *
 *  This file contains portions from the following Mozilla XPCOM files:
 *      xpcom/include/xpcom/nsID.h
 *      xpcom/include/nsIException.h
 *      xpcom/include/nsprpub/prtypes.h
 *      xpcom/include/xpcom/nsISupportsBase.h
 *
 * These files were originally triple-licensed (MPL/GPL2/LGPL2.1). Sun
 * elects to distribute this derived work under the LGPL2.1 only.
 */

/*
 * Copyright (C) 2008-2010 Oracle Corporation
 *
 * This file is part of a free software library; you can redistribute
 * it and/or modify it under the terms of the GNU Lesser General
 * Public License version 2.1 as published by the Free Software
 * Foundation and shipped in the "COPYING.LESSER" file with this library.
 * The library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY of any kind.
 *
 * Oracle LGPL Disclaimer: For the avoidance of doubt, except that if
 * any license choice other than GPL or LGPL is available it will
 * apply instead, Oracle elects to use only the Lesser General Public
 * License version 2.1 (LGPLv2) at this time for any software where
 * a choice of LGPL license versions is made available with the
 * language indicating that LGPLv2 or any later version may be used,
 * or where a choice of which version of the LGPL is applied is
 * otherwise unspecified.
 */

#ifndef ___VirtualBox_CXPCOM_h
# define ___VirtualBox_CXPCOM_h

# ifdef __cplusplus
#  include "VirtualBox_XPCOM.h"
# else /* !__cplusplus */

#  include <stddef.h>
#  include "wchar.h"

#  ifdef WIN32
#   define PR_COM_METHOD __stdcall
#  else
#   define PR_COM_METHOD
#  endif

#  if defined(WIN32)

#   define PR_EXPORT(__type) extern __declspec(dllexport) __type
#   define PR_EXPORT_DATA(__type) extern __declspec(dllexport) __type
#   define PR_IMPORT(__type) __declspec(dllimport) __type
#   define PR_IMPORT_DATA(__type) __declspec(dllimport) __type

#   define PR_EXTERN(__type) extern __declspec(dllexport) __type
#   define PR_IMPLEMENT(__type) __declspec(dllexport) __type
#   define PR_EXTERN_DATA(__type) extern __declspec(dllexport) __type
#   define PR_IMPLEMENT_DATA(__type) __declspec(dllexport) __type

#   define PR_CALLBACK
#   define PR_CALLBACK_DECL
#   define PR_STATIC_CALLBACK(__x) static __x

#  elif defined(XP_BEOS)

#   define PR_EXPORT(__type) extern __declspec(dllexport) __type
#   define PR_EXPORT_DATA(__type) extern __declspec(dllexport) __type
#   define PR_IMPORT(__type) extern __declspec(dllexport) __type
#   define PR_IMPORT_DATA(__type) extern __declspec(dllexport) __type

#   define PR_EXTERN(__type) extern __declspec(dllexport) __type
#   define PR_IMPLEMENT(__type) __declspec(dllexport) __type
#   define PR_EXTERN_DATA(__type) extern __declspec(dllexport) __type
#   define PR_IMPLEMENT_DATA(__type) __declspec(dllexport) __type

#   define PR_CALLBACK
#   define PR_CALLBACK_DECL
#   define PR_STATIC_CALLBACK(__x) static __x

#  elif defined(WIN16)

#   define PR_CALLBACK_DECL        __cdecl

#   if defined(_WINDLL)
#    define PR_EXPORT(__type) extern __type _cdecl _export _loadds
#    define PR_IMPORT(__type) extern __type _cdecl _export _loadds
#    define PR_EXPORT_DATA(__type) extern __type _export
#    define PR_IMPORT_DATA(__type) extern __type _export

#    define PR_EXTERN(__type) extern __type _cdecl _export _loadds
#    define PR_IMPLEMENT(__type) __type _cdecl _export _loadds
#    define PR_EXTERN_DATA(__type) extern __type _export
#    define PR_IMPLEMENT_DATA(__type) __type _export

#    define PR_CALLBACK             __cdecl __loadds
#    define PR_STATIC_CALLBACK(__x) static __x PR_CALLBACK

#   else /* this must be .EXE */
#    define PR_EXPORT(__type) extern __type _cdecl _export
#    define PR_IMPORT(__type) extern __type _cdecl _export
#    define PR_EXPORT_DATA(__type) extern __type _export
#    define PR_IMPORT_DATA(__type) extern __type _export

#    define PR_EXTERN(__type) extern __type _cdecl _export
#    define PR_IMPLEMENT(__type) __type _cdecl _export
#    define PR_EXTERN_DATA(__type) extern __type _export
#    define PR_IMPLEMENT_DATA(__type) __type _export

#    define PR_CALLBACK             __cdecl __loadds
#    define PR_STATIC_CALLBACK(__x) __x PR_CALLBACK
#   endif /* _WINDLL */

#  elif defined(XP_MAC)

#   define PR_EXPORT(__type) extern __declspec(export) __type
#   define PR_EXPORT_DATA(__type) extern __declspec(export) __type
#   define PR_IMPORT(__type) extern __declspec(export) __type
#   define PR_IMPORT_DATA(__type) extern __declspec(export) __type

#   define PR_EXTERN(__type) extern __declspec(export) __type
#   define PR_IMPLEMENT(__type) __declspec(export) __type
#   define PR_EXTERN_DATA(__type) extern __declspec(export) __type
#   define PR_IMPLEMENT_DATA(__type) __declspec(export) __type

#   define PR_CALLBACK
#   define PR_CALLBACK_DECL
#   define PR_STATIC_CALLBACK(__x) static __x

#  elif defined(XP_OS2) && defined(__declspec)

#   define PR_EXPORT(__type) extern __declspec(dllexport) __type
#   define PR_EXPORT_DATA(__type) extern __declspec(dllexport) __type
#   define PR_IMPORT(__type) __declspec(dllimport) __type
#   define PR_IMPORT_DATA(__type) __declspec(dllimport) __type

#   define PR_EXTERN(__type) extern __declspec(dllexport) __type
#   define PR_IMPLEMENT(__type) __declspec(dllexport) __type
#   define PR_EXTERN_DATA(__type) extern __declspec(dllexport) __type
#   define PR_IMPLEMENT_DATA(__type) __declspec(dllexport) __type

#   define PR_CALLBACK
#   define PR_CALLBACK_DECL
#   define PR_STATIC_CALLBACK(__x) static __x

#  elif defined(XP_OS2_VACPP)

#   define PR_EXPORT(__type) extern __type
#   define PR_EXPORT_DATA(__type) extern __type
#   define PR_IMPORT(__type) extern __type
#   define PR_IMPORT_DATA(__type) extern __type

#   define PR_EXTERN(__type) extern __type
#   define PR_IMPLEMENT(__type) __type
#   define PR_EXTERN_DATA(__type) extern __type
#   define PR_IMPLEMENT_DATA(__type) __type
#   define PR_CALLBACK _Optlink
#   define PR_CALLBACK_DECL
#   define PR_STATIC_CALLBACK(__x) static __x PR_CALLBACK

#  else /* Unix */

#   ifdef VBOX_HAVE_VISIBILITY_HIDDEN
#    define PR_EXPORT(__type) __attribute__((visibility("default"))) extern __type
#    define PR_EXPORT_DATA(__type) __attribute__((visibility("default"))) extern __type
#    define PR_IMPORT(__type) extern __type
#    define PR_IMPORT_DATA(__type) extern __type
#    define PR_EXTERN(__type) __attribute__((visibility("default"))) extern __type
#    define PR_IMPLEMENT(__type) __attribute__((visibility("default"))) __type
#    define PR_EXTERN_DATA(__type) __attribute__((visibility("default"))) extern __type
#    define PR_IMPLEMENT_DATA(__type) __attribute__((visibility("default"))) __type
#    define PR_CALLBACK
#    define PR_CALLBACK_DECL
#    define PR_STATIC_CALLBACK(__x) static __x
#   else
#    define PR_EXPORT(__type) extern __type
#    define PR_EXPORT_DATA(__type) extern __type
#    define PR_IMPORT(__type) extern __type
#    define PR_IMPORT_DATA(__type) extern __type
#    define PR_EXTERN(__type) extern __type
#    define PR_IMPLEMENT(__type) __type
#    define PR_EXTERN_DATA(__type) extern __type
#    define PR_IMPLEMENT_DATA(__type) __type
#    define PR_CALLBACK
#    define PR_CALLBACK_DECL
#    define PR_STATIC_CALLBACK(__x) static __x
#   endif
#  endif

#  if defined(_NSPR_BUILD_)
#   define NSPR_API(__type) PR_EXPORT(__type)
#   define NSPR_DATA_API(__type) PR_EXPORT_DATA(__type)
#  else
#   define NSPR_API(__type) PR_IMPORT(__type)
#   define NSPR_DATA_API(__type) PR_IMPORT_DATA(__type)
#  endif

typedef unsigned char PRUint8;
#  if (defined(HPUX) && defined(__cplusplus) \
        && !defined(__GNUC__) && __cplusplus < 199707L) \
    || (defined(SCO) && defined(__cplusplus) \
        && !defined(__GNUC__) && __cplusplus == 1L)
typedef char PRInt8;
#  else
typedef signed char PRInt8;
#  endif

#  define PR_INT8_MAX 127
#  define PR_INT8_MIN (-128)
#  define PR_UINT8_MAX 255U

typedef unsigned short PRUint16;
typedef short PRInt16;

#  define PR_INT16_MAX 32767
#  define PR_INT16_MIN (-32768)
#  define PR_UINT16_MAX 65535U

typedef unsigned int PRUint32;
typedef int PRInt32;
#  define PR_INT32(x)  x
#  define PR_UINT32(x) x ## U

#  define PR_INT32_MAX PR_INT32(2147483647)
#  define PR_INT32_MIN (-PR_INT32_MAX - 1)
#  define PR_UINT32_MAX PR_UINT32(4294967295)

typedef long PRInt64;
typedef unsigned long PRUint64;
typedef int PRIntn;
typedef unsigned int PRUintn;

typedef double          PRFloat64;
typedef size_t PRSize;

typedef ptrdiff_t PRPtrdiff;

typedef unsigned long PRUptrdiff;

typedef PRIntn PRBool;

#  define PR_TRUE 1
#  define PR_FALSE 0

typedef PRUint8 PRPackedBool;

/*
** Status code used by some routines that have a single point of failure or
** special status return.
*/
typedef enum { PR_FAILURE = -1, PR_SUCCESS = 0 } PRStatus;

#  ifndef __PRUNICHAR__
#   define __PRUNICHAR__
#   if defined(WIN32) || defined(XP_MAC)
typedef wchar_t PRUnichar;
#   else
typedef PRUint16 PRUnichar;
#   endif
#  endif

typedef long PRWord;
typedef unsigned long PRUword;

#  define nsnull 0
typedef PRUint32 nsresult;

#  if defined(__GNUC__) && (__GNUC__ > 2)
#   define NS_LIKELY(x)    (__builtin_expect((x), 1))
#   define NS_UNLIKELY(x)  (__builtin_expect((x), 0))
#  else
#   define NS_LIKELY(x)    (x)
#   define NS_UNLIKELY(x)  (x)
#  endif

#  define NS_FAILED(_nsresult) (NS_UNLIKELY((_nsresult) & 0x80000000))
#  define NS_SUCCEEDED(_nsresult) (NS_LIKELY(!((_nsresult) & 0x80000000)))

#  ifdef VBOX_WITH_XPCOM_NAMESPACE_CLEANUP
#   define PR_IntervalNow VBoxNsprPR_IntervalNow
#   define PR_TicksPerSecond VBoxNsprPR_TicksPerSecond
#   define PR_SecondsToInterval VBoxNsprPR_SecondsToInterval
#   define PR_MillisecondsToInterval VBoxNsprPR_MillisecondsToInterval
#   define PR_MicrosecondsToInterval VBoxNsprPR_MicrosecondsToInterval
#   define PR_IntervalToSeconds VBoxNsprPR_IntervalToSeconds
#   define PR_IntervalToMilliseconds VBoxNsprPR_IntervalToMilliseconds
#   define PR_IntervalToMicroseconds VBoxNsprPR_IntervalToMicroseconds
#   define PR_EnterMonitor VBoxNsprPR_EnterMonitor
#   define PR_ExitMonitor VBoxNsprPR_ExitMonitor
#   define PR_Notify VBoxNsprPR_Notify
#   define PR_NotifyAll VBoxNsprPR_NotifyAll
#   define PR_Wait VBoxNsprPR_Wait
#   define PR_NewMonitor VBoxNsprPR_NewMonitor
#   define PR_DestroyMonitor VBoxNsprPR_DestroyMonitor
#  endif /* VBOX_WITH_XPCOM_NAMESPACE_CLEANUP */

typedef PRUint32 PRIntervalTime;

#  define PR_INTERVAL_MIN 1000UL
#  define PR_INTERVAL_MAX 100000UL
#  define PR_INTERVAL_NO_WAIT 0UL
#  define PR_INTERVAL_NO_TIMEOUT 0xffffffffUL

NSPR_API(PRIntervalTime) PR_IntervalNow(void);
NSPR_API(PRUint32) PR_TicksPerSecond(void);
NSPR_API(PRIntervalTime) PR_SecondsToInterval(PRUint32 seconds);
NSPR_API(PRIntervalTime) PR_MillisecondsToInterval(PRUint32 milli);
NSPR_API(PRIntervalTime) PR_MicrosecondsToInterval(PRUint32 micro);
NSPR_API(PRUint32) PR_IntervalToSeconds(PRIntervalTime ticks);
NSPR_API(PRUint32) PR_IntervalToMilliseconds(PRIntervalTime ticks);
NSPR_API(PRUint32) PR_IntervalToMicroseconds(PRIntervalTime ticks);

typedef struct PRMonitor PRMonitor;

NSPR_API(PRMonitor*) PR_NewMonitor(void);
NSPR_API(void) PR_DestroyMonitor(PRMonitor *mon);
NSPR_API(void) PR_EnterMonitor(PRMonitor *mon);
NSPR_API(PRStatus) PR_ExitMonitor(PRMonitor *mon);
NSPR_API(PRStatus) PR_Wait(PRMonitor *mon, PRIntervalTime ticks);
NSPR_API(PRStatus) PR_Notify(PRMonitor *mon);
NSPR_API(PRStatus) PR_NotifyAll(PRMonitor *mon);

#  ifdef VBOX_WITH_XPCOM_NAMESPACE_CLEANUP
#   define PR_CreateThread VBoxNsprPR_CreateThread
#   define PR_JoinThread VBoxNsprPR_JoinThread
#   define PR_Sleep VBoxNsprPR_Sleep
#   define PR_GetCurrentThread VBoxNsprPR_GetCurrentThread
#   define PR_GetThreadState VBoxNsprPR_GetThreadState
#   define PR_SetThreadPrivate VBoxNsprPR_SetThreadPrivate
#   define PR_GetThreadPrivate VBoxNsprPR_GetThreadPrivate
#   define PR_NewThreadPrivateIndex VBoxNsprPR_NewThreadPrivateIndex
#   define PR_GetThreadPriority VBoxNsprPR_GetThreadPriority
#   define PR_SetThreadPriority VBoxNsprPR_SetThreadPriority
#   define PR_Interrupt VBoxNsprPR_Interrupt
#   define PR_ClearInterrupt VBoxNsprPR_ClearInterrupt
#   define PR_BlockInterrupt VBoxNsprPR_BlockInterrupt
#   define PR_UnblockInterrupt VBoxNsprPR_UnblockInterrupt
#   define PR_GetThreadScope VBoxNsprPR_GetThreadScope
#   define PR_GetThreadType VBoxNsprPR_GetThreadType
#  endif /* VBOX_WITH_XPCOM_NAMESPACE_CLEANUP */

typedef struct PRThread PRThread;
typedef struct PRThreadStack PRThreadStack;

typedef enum PRThreadType {
    PR_USER_THREAD,
    PR_SYSTEM_THREAD
} PRThreadType;

typedef enum PRThreadScope {
    PR_LOCAL_THREAD,
    PR_GLOBAL_THREAD,
    PR_GLOBAL_BOUND_THREAD
} PRThreadScope;

typedef enum PRThreadState {
    PR_JOINABLE_THREAD,
    PR_UNJOINABLE_THREAD
} PRThreadState;

typedef enum PRThreadPriority
{
    PR_PRIORITY_FIRST = 0,      /* just a placeholder */
    PR_PRIORITY_LOW = 0,        /* the lowest possible priority */
    PR_PRIORITY_NORMAL = 1,     /* most common expected priority */
    PR_PRIORITY_HIGH = 2,       /* slightly more aggressive scheduling */
    PR_PRIORITY_URGENT = 3,     /* it does little good to have more than one */
    PR_PRIORITY_LAST = 3        /* this is just a placeholder */
} PRThreadPriority;

NSPR_API(PRThread*) PR_CreateThread(PRThreadType type,
                     void (PR_CALLBACK *start)(void *arg),
                     void *arg,
                     PRThreadPriority priority,
                     PRThreadScope scope,
                     PRThreadState state,
                     PRUint32 stackSize);
NSPR_API(PRStatus) PR_JoinThread(PRThread *thread);
NSPR_API(PRThread*) PR_GetCurrentThread(void);
#  ifndef NO_NSPR_10_SUPPORT
#   define PR_CurrentThread() PR_GetCurrentThread() /* for nspr1.0 compat. */
#  endif /* NO_NSPR_10_SUPPORT */
NSPR_API(PRThreadPriority) PR_GetThreadPriority(const PRThread *thread);
NSPR_API(void) PR_SetThreadPriority(PRThread *thread, PRThreadPriority priority);

typedef void (PR_CALLBACK *PRThreadPrivateDTOR)(void *priv);

NSPR_API(PRStatus) PR_NewThreadPrivateIndex(
    PRUintn *newIndex, PRThreadPrivateDTOR destructor);
NSPR_API(PRStatus) PR_SetThreadPrivate(PRUintn tpdIndex, void *priv);
NSPR_API(void*) PR_GetThreadPrivate(PRUintn tpdIndex);
NSPR_API(PRStatus) PR_Interrupt(PRThread *thread);
NSPR_API(void) PR_ClearInterrupt(void);
NSPR_API(void) PR_BlockInterrupt(void);
NSPR_API(void) PR_UnblockInterrupt(void);
NSPR_API(PRStatus) PR_Sleep(PRIntervalTime ticks);
NSPR_API(PRThreadScope) PR_GetThreadScope(const PRThread *thread);
NSPR_API(PRThreadType) PR_GetThreadType(const PRThread *thread);
NSPR_API(PRThreadState) PR_GetThreadState(const PRThread *thread);

#  ifdef VBOX_WITH_XPCOM_NAMESPACE_CLEANUP
#   define PR_DestroyLock VBoxNsprPR_DestroyLock
#   define PR_Lock VBoxNsprPR_Lock
#   define PR_NewLock VBoxNsprPR_NewLock
#   define PR_Unlock VBoxNsprPR_Unlock
#  endif /* VBOX_WITH_XPCOM_NAMESPACE_CLEANUP */

typedef struct PRLock PRLock;

NSPR_API(PRLock*) PR_NewLock(void);
NSPR_API(void) PR_DestroyLock(PRLock *lock);
NSPR_API(void) PR_Lock(PRLock *lock);
NSPR_API(PRStatus) PR_Unlock(PRLock *lock);

#  ifdef VBOX_WITH_XPCOM_NAMESPACE_CLEANUP
#   define PR_NewCondVar VBoxNsprPR_NewCondVar
#   define PR_DestroyCondVar VBoxNsprPR_DestroyCondVar
#   define PR_WaitCondVar VBoxNsprPR_WaitCondVar
#   define PR_NotifyCondVar VBoxNsprPR_NotifyCondVar
#   define PR_NotifyAllCondVar VBoxNsprPR_NotifyAllCondVar
#  endif /* VBOX_WITH_XPCOM_NAMESPACE_CLEANUP */

typedef struct PRCondVar PRCondVar;

NSPR_API(PRCondVar*) PR_NewCondVar(PRLock *lock);
NSPR_API(void) PR_DestroyCondVar(PRCondVar *cvar);
NSPR_API(PRStatus) PR_WaitCondVar(PRCondVar *cvar, PRIntervalTime timeout);
NSPR_API(PRStatus) PR_NotifyCondVar(PRCondVar *cvar);
NSPR_API(PRStatus) PR_NotifyAllCondVar(PRCondVar *cvar);

typedef struct PRCListStr PRCList;

struct PRCListStr {
    PRCList *next;
    PRCList *prev;
};

#  ifdef VBOX_WITH_XPCOM_NAMESPACE_CLEANUP
#   define PL_DestroyEvent VBoxNsplPL_DestroyEvent
#   define PL_HandleEvent VBoxNsplPL_HandleEvent
#   define PL_InitEvent VBoxNsplPL_InitEvent
#   define PL_CreateEventQueue VBoxNsplPL_CreateEventQueue
#   define PL_CreateMonitoredEventQueue VBoxNsplPL_CreateMonitoredEventQueue
#   define PL_CreateNativeEventQueue VBoxNsplPL_CreateNativeEventQueue
#   define PL_DequeueEvent VBoxNsplPL_DequeueEvent
#   define PL_DestroyEventQueue VBoxNsplPL_DestroyEventQueue
#   define PL_EventAvailable VBoxNsplPL_EventAvailable
#   define PL_EventLoop VBoxNsplPL_EventLoop
#   define PL_GetEvent VBoxNsplPL_GetEvent
#   define PL_GetEventOwner VBoxNsplPL_GetEventOwner
#   define PL_GetEventQueueMonitor VBoxNsplPL_GetEventQueueMonitor
#   define PL_GetEventQueueSelectFD VBoxNsplPL_GetEventQueueSelectFD
#   define PL_MapEvents VBoxNsplPL_MapEvents
#   define PL_PostEvent VBoxNsplPL_PostEvent
#   define PL_PostSynchronousEvent VBoxNsplPL_PostSynchronousEvent
#   define PL_ProcessEventsBeforeID VBoxNsplPL_ProcessEventsBeforeID
#   define PL_ProcessPendingEvents VBoxNsplPL_ProcessPendingEvents
#   define PL_RegisterEventIDFunc VBoxNsplPL_RegisterEventIDFunc
#   define PL_RevokeEvents VBoxNsplPL_RevokeEvents
#   define PL_UnregisterEventIDFunc VBoxNsplPL_UnregisterEventIDFunc
#   define PL_WaitForEvent VBoxNsplPL_WaitForEvent
#   define PL_IsQueueNative VBoxNsplPL_IsQueueNative
#   define PL_IsQueueOnCurrentThread VBoxNsplPL_IsQueueOnCurrentThread
#   define PL_FavorPerformanceHint VBoxNsplPL_FavorPerformanceHint
#  endif /* VBOX_WITH_XPCOM_NAMESPACE_CLEANUP */

typedef struct PLEvent PLEvent;
typedef struct PLEventQueue PLEventQueue;

PR_EXTERN(PLEventQueue*)
PL_CreateEventQueue(const char* name, PRThread* handlerThread);
PR_EXTERN(PLEventQueue *)
    PL_CreateNativeEventQueue(
        const char *name,
        PRThread *handlerThread
    );
PR_EXTERN(PLEventQueue *)
    PL_CreateMonitoredEventQueue(
        const char *name,
        PRThread *handlerThread
    );
PR_EXTERN(void)
PL_DestroyEventQueue(PLEventQueue* self);
PR_EXTERN(PRMonitor*)
PL_GetEventQueueMonitor(PLEventQueue* self);

#  define PL_ENTER_EVENT_QUEUE_MONITOR(queue) \
    PR_EnterMonitor(PL_GetEventQueueMonitor(queue))

#  define PL_EXIT_EVENT_QUEUE_MONITOR(queue)  \
    PR_ExitMonitor(PL_GetEventQueueMonitor(queue))

PR_EXTERN(PRStatus) PL_PostEvent(PLEventQueue* self, PLEvent* event);
PR_EXTERN(void*) PL_PostSynchronousEvent(PLEventQueue* self, PLEvent* event);
PR_EXTERN(PLEvent*) PL_GetEvent(PLEventQueue* self);
PR_EXTERN(PRBool) PL_EventAvailable(PLEventQueue* self);

typedef void (PR_CALLBACK *PLEventFunProc)(PLEvent* event, void* data, PLEventQueue* queue);

PR_EXTERN(void) PL_MapEvents(PLEventQueue* self, PLEventFunProc fun, void* data);
PR_EXTERN(void) PL_RevokeEvents(PLEventQueue* self, void* owner);
PR_EXTERN(void) PL_ProcessPendingEvents(PLEventQueue* self);
PR_EXTERN(PLEvent*) PL_WaitForEvent(PLEventQueue* self);
PR_EXTERN(void) PL_EventLoop(PLEventQueue* self);
PR_EXTERN(PRInt32) PL_GetEventQueueSelectFD(PLEventQueue* self);
PR_EXTERN(PRBool) PL_IsQueueOnCurrentThread( PLEventQueue *queue );
PR_EXTERN(PRBool) PL_IsQueueNative(PLEventQueue *queue);

typedef void* (PR_CALLBACK *PLHandleEventProc)(PLEvent* self);
typedef void (PR_CALLBACK *PLDestroyEventProc)(PLEvent* self);
PR_EXTERN(void)
PL_InitEvent(PLEvent* self, void* owner,
             PLHandleEventProc handler,
             PLDestroyEventProc destructor);
PR_EXTERN(void*) PL_GetEventOwner(PLEvent* self);
PR_EXTERN(void) PL_HandleEvent(PLEvent* self);
PR_EXTERN(void) PL_DestroyEvent(PLEvent* self);
PR_EXTERN(void) PL_DequeueEvent(PLEvent* self, PLEventQueue* queue);
PR_EXTERN(void) PL_FavorPerformanceHint(PRBool favorPerformanceOverEventStarvation, PRUint32 starvationDelay);

struct PLEvent {
    PRCList             link;
    PLHandleEventProc   handler;
    PLDestroyEventProc  destructor;
    void*               owner;
    void*               synchronousResult;
    PRLock*             lock;
    PRCondVar*          condVar;
    PRBool              handled;
#  ifdef PL_POST_TIMINGS
    PRIntervalTime      postTime;
#  endif
#  ifdef XP_UNIX
    unsigned long       id;
#  endif /* XP_UNIX */
    /* other fields follow... */
};

#  if defined(XP_WIN) || defined(XP_OS2)

PR_EXTERN(HWND)
    PL_GetNativeEventReceiverWindow(
        PLEventQueue *eqp
    );
#  endif /* XP_WIN || XP_OS2 */

#  ifdef XP_UNIX

PR_EXTERN(PRInt32)
PL_ProcessEventsBeforeID(PLEventQueue *aSelf, unsigned long aID);

typedef unsigned long (PR_CALLBACK *PLGetEventIDFunc)(void *aClosure);

PR_EXTERN(void)
PL_RegisterEventIDFunc(PLEventQueue *aSelf, PLGetEventIDFunc aFunc,
                       void *aClosure);
PR_EXTERN(void) PL_UnregisterEventIDFunc(PLEventQueue *aSelf);

#  endif /* XP_UNIX */

/* Standard "it worked" return value */
#  define NS_OK                              0

#  define NS_ERROR_BASE                      ((nsresult) 0xC1F30000)

/* Returned when an instance is not initialized */
#  define NS_ERROR_NOT_INITIALIZED           (NS_ERROR_BASE + 1)

/* Returned when an instance is already initialized */
#  define NS_ERROR_ALREADY_INITIALIZED       (NS_ERROR_BASE + 2)

/* Returned by a not implemented function */
#  define NS_ERROR_NOT_IMPLEMENTED           ((nsresult) 0x80004001L)

/* Returned when a given interface is not supported. */
#  define NS_NOINTERFACE                     ((nsresult) 0x80004002L)
#  define NS_ERROR_NO_INTERFACE              NS_NOINTERFACE

#  define NS_ERROR_INVALID_POINTER           ((nsresult) 0x80004003L)
#  define NS_ERROR_NULL_POINTER              NS_ERROR_INVALID_POINTER

/* Returned when a function aborts */
#  define NS_ERROR_ABORT                     ((nsresult) 0x80004004L)

/* Returned when a function fails */
#  define NS_ERROR_FAILURE                   ((nsresult) 0x80004005L)

/* Returned when an unexpected error occurs */
#  define NS_ERROR_UNEXPECTED                ((nsresult) 0x8000ffffL)

/* Returned when a memory allocation fails */
#  define NS_ERROR_OUT_OF_MEMORY             ((nsresult) 0x8007000eL)

/* Returned when an illegal value is passed */
#  define NS_ERROR_ILLEGAL_VALUE             ((nsresult) 0x80070057L)
#  define NS_ERROR_INVALID_ARG               NS_ERROR_ILLEGAL_VALUE

/* Returned when a class doesn't allow aggregation */
#  define NS_ERROR_NO_AGGREGATION            ((nsresult) 0x80040110L)

/* Returned when an operation can't complete due to an unavailable resource */
#  define NS_ERROR_NOT_AVAILABLE             ((nsresult) 0x80040111L)

/* Returned when a class is not registered */
#  define NS_ERROR_FACTORY_NOT_REGISTERED    ((nsresult) 0x80040154L)

/* Returned when a class cannot be registered, but may be tried again later */
#  define NS_ERROR_FACTORY_REGISTER_AGAIN    ((nsresult) 0x80040155L)

/* Returned when a dynamically loaded factory couldn't be found */
#  define NS_ERROR_FACTORY_NOT_LOADED        ((nsresult) 0x800401f8L)

/* Returned when a factory doesn't support signatures */
#  define NS_ERROR_FACTORY_NO_SIGNATURE_SUPPORT \
                                           (NS_ERROR_BASE + 0x101)

/* Returned when a factory already is registered */
#  define NS_ERROR_FACTORY_EXISTS            (NS_ERROR_BASE + 0x100)


/**
 * An "interface id" which can be used to uniquely identify a given
 * interface.
 * A "unique identifier". This is modeled after OSF DCE UUIDs.
 */

struct nsID {
  PRUint32 m0;
  PRUint16 m1;
  PRUint16 m2;
  PRUint8 m3[8];
};

typedef struct nsID nsID;
typedef nsID nsIID;

struct nsISupports;   /* forward declaration */
struct nsIStackFrame; /* forward declaration */
struct nsIException;  /* forward declaration */
typedef struct nsISupports nsISupports;     /* forward declaration */
typedef struct nsIStackFrame nsIStackFrame; /* forward declaration */
typedef struct nsIException nsIException;   /* forward declaration */

/**
 * IID for the nsISupports interface
 * {00000000-0000-0000-c000-000000000046}
 *
 * To maintain binary compatibility with COM's IUnknown, we define the IID
 * of nsISupports to be the same as that of COM's IUnknown.
 */
#  define NS_ISUPPORTS_IID                                                      \
  { 0x00000000, 0x0000, 0x0000,                                               \
    {0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46} }

/**
 * Reference count values
 *
 * This is the return type for AddRef() and Release() in nsISupports.
 * IUnknown of COM returns an unsigned long from equivalent functions.
 * The following ifdef exists to maintain binary compatibility with
 * IUnknown.
 */

/**
 * Basic component object model interface. Objects which implement
 * this interface support runtime interface discovery (QueryInterface)
 * and a reference counted memory model (AddRef/Release). This is
 * modelled after the win32 IUnknown API.
 */
struct nsISupports_vtbl {

  /**
   * @name Methods
   */

  /**
   * A run time mechanism for interface discovery.
   * @param aIID         [in]  A requested interface IID
   * @param aInstancePtr [out] A pointer to an interface pointer to
   *                           receive the result.
   * @return            NS_OK if the interface is supported by the associated
   *                          instance, NS_NOINTERFACE if it is not.
   * NS_ERROR_INVALID_POINTER if aInstancePtr is NULL.
   */
  nsresult PR_COM_METHOD (*QueryInterface)(nsISupports *pThis, const nsID *iid, void **resultp);
  /**
   * Increases the reference count for this interface.
   * The associated instance will not be deleted unless
   * the reference count is returned to zero.
   *
   * @return The resulting reference count.
   */
  nsresult PR_COM_METHOD (*AddRef)(nsISupports *pThis);

  /**
   * Decreases the reference count for this interface.
   * Generally, if the reference count returns to zero,
   * the associated instance is deleted.
   *
   * @return The resulting reference count.
   */
  nsresult PR_COM_METHOD (*Release)(nsISupports *pThis);

#  ifdef WIN32
  /* The MSCOM implementation has some additional methods here.
   * So add them here to get correct binary layout of the object.
   * In API version 4.x this affects all types. */
  nsresult PR_COM_METHOD (*GetTypeInfoCount)(nsISupports *pThis);
  nsresult PR_COM_METHOD (*GetTypeInfo)(nsISupports *pThis);
  nsresult PR_COM_METHOD (*GetIDsOfNames)(nsISupports *pThis);
  nsresult PR_COM_METHOD (*Invoke)(nsISupports *pThis);
#  endif
};

struct nsISupports {
    struct nsISupports_vtbl *vtbl;
};

/* starting interface:    nsIException */
#  define NS_IEXCEPTION_IID_STR "f3a8d3b4-c424-4edc-8bf6-8974c983ba78"

#  define NS_IEXCEPTION_IID \
  {0xf3a8d3b4, 0xc424, 0x4edc, \
    { 0x8b, 0xf6, 0x89, 0x74, 0xc9, 0x83, 0xba, 0x78 }}

struct nsIException_vtbl {

  /* Methods from the Class nsISupports */
  struct nsISupports_vtbl nsisupports;

  /* readonly attribute string message; */
  nsresult PR_COM_METHOD (*GetMessage)(nsIException *pThis, PRUnichar * *aMessage);

  /* readonly attribute nsresult (*result; */
  nsresult PR_COM_METHOD (*GetResult)(nsIException *pThis, nsresult *aResult);

  /* readonly attribute string name; */
  nsresult PR_COM_METHOD (*GetName)(nsIException *pThis, PRUnichar * *aName);

  /* readonly attribute string filename; */
  nsresult PR_COM_METHOD (*GetFilename)(nsIException *pThis, PRUnichar * *aFilename);

  /* readonly attribute PRUint32 lineNumber; */
  nsresult PR_COM_METHOD (*GetLineNumber)(nsIException *pThis, PRUint32 *aLineNumber);

  /* readonly attribute PRUint32 columnNumber; */
  nsresult PR_COM_METHOD (*GetColumnNumber)(nsIException *pThis, PRUint32 *aColumnNumber);

  /* readonly attribute nsIStackFrame location; */
  nsresult PR_COM_METHOD (*GetLocation)(nsIException *pThis, nsIStackFrame * *aLocation);

  /* readonly attribute nsIException inner; */
  nsresult PR_COM_METHOD (*GetInner)(nsIException *pThis, nsIException * *aInner);

  /* readonly attribute nsISupports data; */
  nsresult PR_COM_METHOD (*GetData)(nsIException *pThis, nsISupports * *aData);

  /* string toString (); */
  nsresult PR_COM_METHOD (*ToString)(nsIException *pThis, PRUnichar **_retval);
};

struct nsIException {
    struct nsIException_vtbl *vtbl;
};

/* starting interface:    nsIStackFrame */
#  define NS_ISTACKFRAME_IID_STR "91d82105-7c62-4f8b-9779-154277c0ee90"

#  define NS_ISTACKFRAME_IID \
  {0x91d82105, 0x7c62, 0x4f8b, \
    { 0x97, 0x79, 0x15, 0x42, 0x77, 0xc0, 0xee, 0x90 }}

struct nsIStackFrame_vtbl {

  /* Methods from the Class nsISupports */
  struct nsISupports_vtbl nsisupports;

  /* readonly attribute PRUint32 language; */
  nsresult PR_COM_METHOD (*GetLanguage)(nsIStackFrame *pThis, PRUint32 *aLanguage);

  /* readonly attribute string languageName; */
  nsresult PR_COM_METHOD (*GetLanguageName)(nsIStackFrame *pThis, PRUnichar * *aLanguageName);

  /* readonly attribute string filename; */
  nsresult PR_COM_METHOD (*GetFilename)(nsIStackFrame *pThis, PRUnichar * *aFilename);

  /* readonly attribute string name; */
  nsresult PR_COM_METHOD (*GetName)(nsIStackFrame *pThis, PRUnichar * *aName);

  /* readonly attribute PRInt32 lineNumber; */
  nsresult PR_COM_METHOD (*GetLineNumber)(nsIStackFrame *pThis, PRInt32 *aLineNumber);

  /* readonly attribute string sourceLine; */
  nsresult PR_COM_METHOD (*GetSourceLine)(nsIStackFrame *pThis, PRUnichar * *aSourceLine);

  /* readonly attribute nsIStackFrame caller; */
  nsresult PR_COM_METHOD (*GetCaller)(nsIStackFrame *pThis, nsIStackFrame * *aCaller);

  /* string toString (); */
  nsresult PR_COM_METHOD (*ToString)(nsIStackFrame *pThis, PRUnichar **_retval);
};

struct nsIStackFrame {
    struct nsIStackFrame_vtbl *vtbl;
};

/* starting interface:    nsIEventTarget */
#  define NS_IEVENTTARGET_IID_STR "ea99ad5b-cc67-4efb-97c9-2ef620a59f2a"

#  define NS_IEVENTTARGET_IID \
  {0xea99ad5b, 0xcc67, 0x4efb, \
    { 0x97, 0xc9, 0x2e, 0xf6, 0x20, 0xa5, 0x9f, 0x2a }}

struct nsIEventTarget;
typedef struct nsIEventTarget nsIEventTarget;

struct nsIEventTarget_vtbl {

    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*PostEvent)(nsIEventTarget *pThis, PLEvent * aEvent);

    nsresult PR_COM_METHOD (*IsOnCurrentThread)(nsIEventTarget *pThis, PRBool *_retval);

};

struct nsIEventTarget {
    struct nsIEventTarget_vtbl *vtbl;
};

/* starting interface:    nsIEventQueue */
#  define NS_IEVENTQUEUE_IID_STR "176afb41-00a4-11d3-9f2a-00400553eef0"

#  define NS_IEVENTQUEUE_IID \
  {0x176afb41, 0x00a4, 0x11d3, \
    { 0x9f, 0x2a, 0x00, 0x40, 0x05, 0x53, 0xee, 0xf0 }}

struct nsIEventQueue;
typedef struct nsIEventQueue nsIEventQueue;

struct nsIEventQueue_vtbl {

    struct nsIEventTarget_vtbl nsieventtarget;

    nsresult PR_COM_METHOD (*InitEvent)(nsIEventQueue *pThis, PLEvent * aEvent, void * owner, PLHandleEventProc handler, PLDestroyEventProc destructor);

    nsresult PR_COM_METHOD (*PostSynchronousEvent)(nsIEventQueue *pThis, PLEvent * aEvent, void * *aResult);

    nsresult PR_COM_METHOD (*PendingEvents)(nsIEventQueue *pThis, PRBool *_retval);

    nsresult PR_COM_METHOD (*ProcessPendingEvents)(nsIEventQueue *pThis);

    nsresult PR_COM_METHOD (*EventLoop)(nsIEventQueue *pThis);

    nsresult PR_COM_METHOD (*EventAvailable)(nsIEventQueue *pThis, PRBool *aResult);

    nsresult PR_COM_METHOD (*GetEvent)(nsIEventQueue *pThis, PLEvent * *_retval);

    nsresult PR_COM_METHOD (*HandleEvent)(nsIEventQueue *pThis, PLEvent * aEvent);

    nsresult PR_COM_METHOD (*WaitForEvent)(nsIEventQueue *pThis, PLEvent * *_retval);

    PRInt32 PR_COM_METHOD (*GetEventQueueSelectFD)(nsIEventQueue *pThis);

    nsresult PR_COM_METHOD (*Init)(nsIEventQueue *pThis, PRBool aNative);

    nsresult PR_COM_METHOD (*InitFromPRThread)(nsIEventQueue *pThis, PRThread * thread, PRBool aNative);

    nsresult PR_COM_METHOD (*InitFromPLQueue)(nsIEventQueue *pThis, PLEventQueue * aQueue);

    nsresult PR_COM_METHOD (*EnterMonitor)(nsIEventQueue *pThis);

    nsresult PR_COM_METHOD (*ExitMonitor)(nsIEventQueue *pThis);

    nsresult PR_COM_METHOD (*RevokeEvents)(nsIEventQueue *pThis, void * owner);

    nsresult PR_COM_METHOD (*GetPLEventQueue)(nsIEventQueue *pThis, PLEventQueue * *_retval);

    nsresult PR_COM_METHOD (*IsQueueNative)(nsIEventQueue *pThis, PRBool *_retval);

    nsresult PR_COM_METHOD (*StopAcceptingEvents)(nsIEventQueue *pThis);

};

struct nsIEventQueue {
    struct nsIEventQueue_vtbl *vtbl;
};


#  define VBOX_E_OBJECT_NOT_FOUND 0x80BB0001
#  define VBOX_E_INVALID_VM_STATE 0x80BB0002
#  define VBOX_E_VM_ERROR 0x80BB0003
#  define VBOX_E_FILE_ERROR 0x80BB0004
#  define VBOX_E_IPRT_ERROR 0x80BB0005
#  define VBOX_E_PDM_ERROR 0x80BB0006
#  define VBOX_E_INVALID_OBJECT_STATE 0x80BB0007
#  define VBOX_E_HOST_ERROR 0x80BB0008
#  define VBOX_E_NOT_SUPPORTED 0x80BB0009
#  define VBOX_E_XML_ERROR 0x80BB000A
#  define VBOX_E_INVALID_SESSION_STATE 0x80BB000B
#  define VBOX_E_OBJECT_IN_USE 0x80BB000C


struct IVirtualBoxErrorInfo;
struct IDHCPServer;
struct IVirtualBox;
struct IVFSExplorer;
struct IAppliance;
struct IVirtualSystemDescription;
struct IInternalMachineControl;
struct IBIOSSettings;
struct IEventContext;
struct IPciAddress;
struct IPciDeviceAttachment;
struct IMachine;
struct IVRDEServerInfo;
struct IConsole;
struct IHostNetworkInterface;
struct IHost;
struct ISystemProperties;
struct IGuestOSType;
struct IGuest;
struct IProgress;
struct ISnapshot;
struct IMediumAttachment;
struct IMedium;
struct IMediumFormat;
struct IKeyboard;
struct IMouse;
struct IFramebuffer;
struct IFramebufferOverlay;
struct IDisplay;
struct INetworkAdapter;
struct ISerialPort;
struct IParallelPort;
struct IMachineDebugger;
struct IUSBController;
struct IUSBDevice;
struct IUSBDeviceFilter;
struct IHostUSBDevice;
struct IHostUSBDeviceFilter;
struct IAudioAdapter;
struct IVRDEServer;
struct ISharedFolder;
struct IInternalSessionControl;
struct ISession;
struct IStorageController;
struct IManagedObjectRef;
struct IWebsessionManager;
struct IPerformanceMetric;
struct IPerformanceCollector;
struct INATEngine;
struct IExtPackPlugIn;
struct IExtPackBase;
struct IExtPack;
struct IExtPackFile;
struct IExtPackManager;
struct IBandwidthGroup;
struct IBandwidthControl;
struct IVirtualBoxClient;
struct IEventSource;
struct IEventListener;
struct IEvent;
struct IReusableEvent;
struct IMachineEvent;
struct IMachineStateChangedEvent;
struct IMachineDataChangedEvent;
struct IMediumRegisteredEvent;
struct IMachineRegisteredEvent;
struct ISessionStateChangedEvent;
struct IGuestPropertyChangedEvent;
struct ISnapshotEvent;
struct ISnapshotTakenEvent;
struct ISnapshotDeletedEvent;
struct ISnapshotChangedEvent;
struct IMousePointerShapeChangedEvent;
struct IMouseCapabilityChangedEvent;
struct IKeyboardLedsChangedEvent;
struct IStateChangedEvent;
struct IAdditionsStateChangedEvent;
struct INetworkAdapterChangedEvent;
struct ISerialPortChangedEvent;
struct IParallelPortChangedEvent;
struct IStorageControllerChangedEvent;
struct IMediumChangedEvent;
struct ICPUChangedEvent;
struct ICPUExecutionCapChangedEvent;
struct IGuestKeyboardEvent;
struct IGuestMouseEvent;
struct IVRDEServerChangedEvent;
struct IVRDEServerInfoChangedEvent;
struct IUSBControllerChangedEvent;
struct IUSBDeviceStateChangedEvent;
struct ISharedFolderChangedEvent;
struct IRuntimeErrorEvent;
struct IEventSourceChangedEvent;
struct IExtraDataChangedEvent;
struct IVetoEvent;
struct IExtraDataCanChangeEvent;
struct ICanShowWindowEvent;
struct IShowWindowEvent;
struct INATRedirectEvent;
struct IHostPciDevicePlugEvent;
struct IVBoxSVCAvailabilityChangedEvent;
struct IBandwidthGroupChangedEvent;
struct IGuestMonitorChangedEvent;

typedef struct IVirtualBoxErrorInfo IVirtualBoxErrorInfo;
typedef struct IDHCPServer IDHCPServer;
typedef struct IVirtualBox IVirtualBox;
typedef struct IVFSExplorer IVFSExplorer;
typedef struct IAppliance IAppliance;
typedef struct IVirtualSystemDescription IVirtualSystemDescription;
typedef struct IInternalMachineControl IInternalMachineControl;
typedef struct IBIOSSettings IBIOSSettings;
typedef struct IEventContext IEventContext;
typedef struct IPciAddress IPciAddress;
typedef struct IPciDeviceAttachment IPciDeviceAttachment;
typedef struct IMachine IMachine;
typedef struct IVRDEServerInfo IVRDEServerInfo;
typedef struct IConsole IConsole;
typedef struct IHostNetworkInterface IHostNetworkInterface;
typedef struct IHost IHost;
typedef struct ISystemProperties ISystemProperties;
typedef struct IGuestOSType IGuestOSType;
typedef struct IGuest IGuest;
typedef struct IProgress IProgress;
typedef struct ISnapshot ISnapshot;
typedef struct IMediumAttachment IMediumAttachment;
typedef struct IMedium IMedium;
typedef struct IMediumFormat IMediumFormat;
typedef struct IKeyboard IKeyboard;
typedef struct IMouse IMouse;
typedef struct IFramebuffer IFramebuffer;
typedef struct IFramebufferOverlay IFramebufferOverlay;
typedef struct IDisplay IDisplay;
typedef struct INetworkAdapter INetworkAdapter;
typedef struct ISerialPort ISerialPort;
typedef struct IParallelPort IParallelPort;
typedef struct IMachineDebugger IMachineDebugger;
typedef struct IUSBController IUSBController;
typedef struct IUSBDevice IUSBDevice;
typedef struct IUSBDeviceFilter IUSBDeviceFilter;
typedef struct IHostUSBDevice IHostUSBDevice;
typedef struct IHostUSBDeviceFilter IHostUSBDeviceFilter;
typedef struct IAudioAdapter IAudioAdapter;
typedef struct IVRDEServer IVRDEServer;
typedef struct ISharedFolder ISharedFolder;
typedef struct IInternalSessionControl IInternalSessionControl;
typedef struct ISession ISession;
typedef struct IStorageController IStorageController;
typedef struct IManagedObjectRef IManagedObjectRef;
typedef struct IWebsessionManager IWebsessionManager;
typedef struct IPerformanceMetric IPerformanceMetric;
typedef struct IPerformanceCollector IPerformanceCollector;
typedef struct INATEngine INATEngine;
typedef struct IExtPackPlugIn IExtPackPlugIn;
typedef struct IExtPackBase IExtPackBase;
typedef struct IExtPack IExtPack;
typedef struct IExtPackFile IExtPackFile;
typedef struct IExtPackManager IExtPackManager;
typedef struct IBandwidthGroup IBandwidthGroup;
typedef struct IBandwidthControl IBandwidthControl;
typedef struct IVirtualBoxClient IVirtualBoxClient;
typedef struct IEventSource IEventSource;
typedef struct IEventListener IEventListener;
typedef struct IEvent IEvent;
typedef struct IReusableEvent IReusableEvent;
typedef struct IMachineEvent IMachineEvent;
typedef struct IMachineStateChangedEvent IMachineStateChangedEvent;
typedef struct IMachineDataChangedEvent IMachineDataChangedEvent;
typedef struct IMediumRegisteredEvent IMediumRegisteredEvent;
typedef struct IMachineRegisteredEvent IMachineRegisteredEvent;
typedef struct ISessionStateChangedEvent ISessionStateChangedEvent;
typedef struct IGuestPropertyChangedEvent IGuestPropertyChangedEvent;
typedef struct ISnapshotEvent ISnapshotEvent;
typedef struct ISnapshotTakenEvent ISnapshotTakenEvent;
typedef struct ISnapshotDeletedEvent ISnapshotDeletedEvent;
typedef struct ISnapshotChangedEvent ISnapshotChangedEvent;
typedef struct IMousePointerShapeChangedEvent IMousePointerShapeChangedEvent;
typedef struct IMouseCapabilityChangedEvent IMouseCapabilityChangedEvent;
typedef struct IKeyboardLedsChangedEvent IKeyboardLedsChangedEvent;
typedef struct IStateChangedEvent IStateChangedEvent;
typedef struct IAdditionsStateChangedEvent IAdditionsStateChangedEvent;
typedef struct INetworkAdapterChangedEvent INetworkAdapterChangedEvent;
typedef struct ISerialPortChangedEvent ISerialPortChangedEvent;
typedef struct IParallelPortChangedEvent IParallelPortChangedEvent;
typedef struct IStorageControllerChangedEvent IStorageControllerChangedEvent;
typedef struct IMediumChangedEvent IMediumChangedEvent;
typedef struct ICPUChangedEvent ICPUChangedEvent;
typedef struct ICPUExecutionCapChangedEvent ICPUExecutionCapChangedEvent;
typedef struct IGuestKeyboardEvent IGuestKeyboardEvent;
typedef struct IGuestMouseEvent IGuestMouseEvent;
typedef struct IVRDEServerChangedEvent IVRDEServerChangedEvent;
typedef struct IVRDEServerInfoChangedEvent IVRDEServerInfoChangedEvent;
typedef struct IUSBControllerChangedEvent IUSBControllerChangedEvent;
typedef struct IUSBDeviceStateChangedEvent IUSBDeviceStateChangedEvent;
typedef struct ISharedFolderChangedEvent ISharedFolderChangedEvent;
typedef struct IRuntimeErrorEvent IRuntimeErrorEvent;
typedef struct IEventSourceChangedEvent IEventSourceChangedEvent;
typedef struct IExtraDataChangedEvent IExtraDataChangedEvent;
typedef struct IVetoEvent IVetoEvent;
typedef struct IExtraDataCanChangeEvent IExtraDataCanChangeEvent;
typedef struct ICanShowWindowEvent ICanShowWindowEvent;
typedef struct IShowWindowEvent IShowWindowEvent;
typedef struct INATRedirectEvent INATRedirectEvent;
typedef struct IHostPciDevicePlugEvent IHostPciDevicePlugEvent;
typedef struct IVBoxSVCAvailabilityChangedEvent IVBoxSVCAvailabilityChangedEvent;
typedef struct IBandwidthGroupChangedEvent IBandwidthGroupChangedEvent;
typedef struct IGuestMonitorChangedEvent IGuestMonitorChangedEvent;

/* Start of enum SettingsVersion Declaration */
#  define SETTINGSVERSION_IID_STR "52bd6f5f-1adb-4493-975d-581a9c4b803f"
#  define SETTINGSVERSION_IID { \
    0x52bd6f5f, 0x1adb, 0x4493, \
    { 0x97, 0x5d, 0x58, 0x1a, 0x9c, 0x4b, 0x80, 0x3f } \
}
enum SettingsVersion
{
    SettingsVersion_Null = 0,
    SettingsVersion_v1_0 = 1,
    SettingsVersion_v1_1 = 2,
    SettingsVersion_v1_2 = 3,
    SettingsVersion_v1_3pre = 4,
    SettingsVersion_v1_3 = 5,
    SettingsVersion_v1_4 = 6,
    SettingsVersion_v1_5 = 7,
    SettingsVersion_v1_6 = 8,
    SettingsVersion_v1_7 = 9,
    SettingsVersion_v1_8 = 10,
    SettingsVersion_v1_9 = 11,
    SettingsVersion_v1_10 = 12,
    SettingsVersion_v1_11 = 13,
    SettingsVersion_Future = 99999
};
/* End of enum SettingsVersion Declaration */


/* Start of enum AccessMode Declaration */
#  define ACCESSMODE_IID_STR "1da0007c-ddf7-4be8-bcac-d84a1558785f"
#  define ACCESSMODE_IID { \
    0x1da0007c, 0xddf7, 0x4be8, \
    { 0xbc, 0xac, 0xd8, 0x4a, 0x15, 0x58, 0x78, 0x5f } \
}
enum AccessMode
{
    AccessMode_ReadOnly = 1,
    AccessMode_ReadWrite = 2
};
/* End of enum AccessMode Declaration */


/* Start of enum MachineState Declaration */
#  define MACHINESTATE_IID_STR "ec6c6a9e-113d-4ff4-b44f-0b69f21c97fe"
#  define MACHINESTATE_IID { \
    0xec6c6a9e, 0x113d, 0x4ff4, \
    { 0xb4, 0x4f, 0x0b, 0x69, 0xf2, 0x1c, 0x97, 0xfe } \
}
enum MachineState
{
    MachineState_Null = 0,
    MachineState_PoweredOff = 1,
    MachineState_Saved = 2,
    MachineState_Teleported = 3,
    MachineState_Aborted = 4,
    MachineState_Running = 5,
    MachineState_Paused = 6,
    MachineState_Stuck = 7,
    MachineState_Teleporting = 8,
    MachineState_LiveSnapshotting = 9,
    MachineState_Starting = 10,
    MachineState_Stopping = 11,
    MachineState_Saving = 12,
    MachineState_Restoring = 13,
    MachineState_TeleportingPausedVM = 14,
    MachineState_TeleportingIn = 15,
    MachineState_FaultTolerantSyncing = 16,
    MachineState_DeletingSnapshotOnline = 17,
    MachineState_DeletingSnapshotPaused = 18,
    MachineState_RestoringSnapshot = 19,
    MachineState_DeletingSnapshot = 20,
    MachineState_SettingUp = 21,
    MachineState_FirstOnline = 5,
    MachineState_LastOnline = 18,
    MachineState_FirstTransient = 8,
    MachineState_LastTransient = 21
};
/* End of enum MachineState Declaration */


/* Start of enum SessionState Declaration */
#  define SESSIONSTATE_IID_STR "cf2700c0-ea4b-47ae-9725-7810114b94d8"
#  define SESSIONSTATE_IID { \
    0xcf2700c0, 0xea4b, 0x47ae, \
    { 0x97, 0x25, 0x78, 0x10, 0x11, 0x4b, 0x94, 0xd8 } \
}
enum SessionState
{
    SessionState_Null = 0,
    SessionState_Unlocked = 1,
    SessionState_Locked = 2,
    SessionState_Spawning = 3,
    SessionState_Unlocking = 4
};
/* End of enum SessionState Declaration */


/* Start of enum CPUPropertyType Declaration */
#  define CPUPROPERTYTYPE_IID_STR "24d356a6-2f45-4abd-b977-1cbe9c4701f5"
#  define CPUPROPERTYTYPE_IID { \
    0x24d356a6, 0x2f45, 0x4abd, \
    { 0xb9, 0x77, 0x1c, 0xbe, 0x9c, 0x47, 0x01, 0xf5 } \
}
enum CPUPropertyType
{
    CPUPropertyType_Null = 0,
    CPUPropertyType_PAE = 1,
    CPUPropertyType_Synthetic = 2
};
/* End of enum CPUPropertyType Declaration */


/* Start of enum HWVirtExPropertyType Declaration */
#  define HWVIRTEXPROPERTYTYPE_IID_STR "ce81dfdd-d2b8-4a90-bbea-40ee8b7ffcee"
#  define HWVIRTEXPROPERTYTYPE_IID { \
    0xce81dfdd, 0xd2b8, 0x4a90, \
    { 0xbb, 0xea, 0x40, 0xee, 0x8b, 0x7f, 0xfc, 0xee } \
}
enum HWVirtExPropertyType
{
    HWVirtExPropertyType_Null = 0,
    HWVirtExPropertyType_Enabled = 1,
    HWVirtExPropertyType_Exclusive = 2,
    HWVirtExPropertyType_VPID = 3,
    HWVirtExPropertyType_NestedPaging = 4,
    HWVirtExPropertyType_LargePages = 5,
    HWVirtExPropertyType_Force = 6
};
/* End of enum HWVirtExPropertyType Declaration */


/* Start of enum FaultToleranceState Declaration */
#  define FAULTTOLERANCESTATE_IID_STR "5124f7ec-6b67-493c-9dee-ee45a44114e1"
#  define FAULTTOLERANCESTATE_IID { \
    0x5124f7ec, 0x6b67, 0x493c, \
    { 0x9d, 0xee, 0xee, 0x45, 0xa4, 0x41, 0x14, 0xe1 } \
}
enum FaultToleranceState
{
    FaultToleranceState_Inactive = 1,
    FaultToleranceState_Master = 2,
    FaultToleranceState_Standby = 3
};
/* End of enum FaultToleranceState Declaration */


/* Start of enum LockType Declaration */
#  define LOCKTYPE_IID_STR "138b53f8-db4b-47c5-b32b-4ef52f769413"
#  define LOCKTYPE_IID { \
    0x138b53f8, 0xdb4b, 0x47c5, \
    { 0xb3, 0x2b, 0x4e, 0xf5, 0x2f, 0x76, 0x94, 0x13 } \
}
enum LockType
{
    LockType_Write = 2,
    LockType_Shared = 1
};
/* End of enum LockType Declaration */


/* Start of enum SessionType Declaration */
#  define SESSIONTYPE_IID_STR "A13C02CB-0C2C-421E-8317-AC0E8AAA153A"
#  define SESSIONTYPE_IID { \
    0xA13C02CB, 0x0C2C, 0x421E, \
    { 0x83, 0x17, 0xAC, 0x0E, 0x8A, 0xAA, 0x15, 0x3A } \
}
enum SessionType
{
    SessionType_Null = 0,
    SessionType_WriteLock = 1,
    SessionType_Remote = 2,
    SessionType_Shared = 3
};
/* End of enum SessionType Declaration */


/* Start of enum DeviceType Declaration */
#  define DEVICETYPE_IID_STR "6d9420f7-0b56-4636-99f9-7346f1b01e57"
#  define DEVICETYPE_IID { \
    0x6d9420f7, 0x0b56, 0x4636, \
    { 0x99, 0xf9, 0x73, 0x46, 0xf1, 0xb0, 0x1e, 0x57 } \
}
enum DeviceType
{
    DeviceType_Null = 0,
    DeviceType_Floppy = 1,
    DeviceType_DVD = 2,
    DeviceType_HardDisk = 3,
    DeviceType_Network = 4,
    DeviceType_USB = 5,
    DeviceType_SharedFolder = 6
};
/* End of enum DeviceType Declaration */


/* Start of enum DeviceActivity Declaration */
#  define DEVICEACTIVITY_IID_STR "6FC8AEAA-130A-4eb5-8954-3F921422D707"
#  define DEVICEACTIVITY_IID { \
    0x6FC8AEAA, 0x130A, 0x4eb5, \
    { 0x89, 0x54, 0x3F, 0x92, 0x14, 0x22, 0xD7, 0x07 } \
}
enum DeviceActivity
{
    DeviceActivity_Null = 0,
    DeviceActivity_Idle = 1,
    DeviceActivity_Reading = 2,
    DeviceActivity_Writing = 3
};
/* End of enum DeviceActivity Declaration */


/* Start of enum ClipboardMode Declaration */
#  define CLIPBOARDMODE_IID_STR "33364716-4008-4701-8f14-be0fa3d62950"
#  define CLIPBOARDMODE_IID { \
    0x33364716, 0x4008, 0x4701, \
    { 0x8f, 0x14, 0xbe, 0x0f, 0xa3, 0xd6, 0x29, 0x50 } \
}
enum ClipboardMode
{
    ClipboardMode_Disabled = 0,
    ClipboardMode_HostToGuest = 1,
    ClipboardMode_GuestToHost = 2,
    ClipboardMode_Bidirectional = 3
};
/* End of enum ClipboardMode Declaration */


/* Start of enum Scope Declaration */
#  define SCOPE_IID_STR "7c91096e-499e-4eca-9f9b-9001438d7855"
#  define SCOPE_IID { \
    0x7c91096e, 0x499e, 0x4eca, \
    { 0x9f, 0x9b, 0x90, 0x01, 0x43, 0x8d, 0x78, 0x55 } \
}
enum Scope
{
    Scope_Global = 0,
    Scope_Machine = 1,
    Scope_Session = 2
};
/* End of enum Scope Declaration */


/* Start of enum BIOSBootMenuMode Declaration */
#  define BIOSBOOTMENUMODE_IID_STR "ae4fb9f7-29d2-45b4-b2c7-d579603135d5"
#  define BIOSBOOTMENUMODE_IID { \
    0xae4fb9f7, 0x29d2, 0x45b4, \
    { 0xb2, 0xc7, 0xd5, 0x79, 0x60, 0x31, 0x35, 0xd5 } \
}
enum BIOSBootMenuMode
{
    BIOSBootMenuMode_Disabled = 0,
    BIOSBootMenuMode_MenuOnly = 1,
    BIOSBootMenuMode_MessageAndMenu = 2
};
/* End of enum BIOSBootMenuMode Declaration */


/* Start of enum ProcessorFeature Declaration */
#  define PROCESSORFEATURE_IID_STR "64c38e6b-8bcf-45ad-ac03-9b406287c5bf"
#  define PROCESSORFEATURE_IID { \
    0x64c38e6b, 0x8bcf, 0x45ad, \
    { 0xac, 0x03, 0x9b, 0x40, 0x62, 0x87, 0xc5, 0xbf } \
}
enum ProcessorFeature
{
    ProcessorFeature_HWVirtEx = 0,
    ProcessorFeature_PAE = 1,
    ProcessorFeature_LongMode = 2,
    ProcessorFeature_NestedPaging = 3
};
/* End of enum ProcessorFeature Declaration */


/* Start of enum FirmwareType Declaration */
#  define FIRMWARETYPE_IID_STR "b903f264-c230-483e-ac74-2b37ce60d371"
#  define FIRMWARETYPE_IID { \
    0xb903f264, 0xc230, 0x483e, \
    { 0xac, 0x74, 0x2b, 0x37, 0xce, 0x60, 0xd3, 0x71 } \
}
enum FirmwareType
{
    FirmwareType_BIOS = 1,
    FirmwareType_EFI = 2,
    FirmwareType_EFI32 = 3,
    FirmwareType_EFI64 = 4,
    FirmwareType_EFIDUAL = 5
};
/* End of enum FirmwareType Declaration */


/* Start of enum PointingHidType Declaration */
#  define POINTINGHIDTYPE_IID_STR "0d3c17a2-821a-4b2e-ae41-890c6c60aa97"
#  define POINTINGHIDTYPE_IID { \
    0x0d3c17a2, 0x821a, 0x4b2e, \
    { 0xae, 0x41, 0x89, 0x0c, 0x6c, 0x60, 0xaa, 0x97 } \
}
enum PointingHidType
{
    PointingHidType_None = 1,
    PointingHidType_PS2Mouse = 2,
    PointingHidType_USBMouse = 3,
    PointingHidType_USBTablet = 4,
    PointingHidType_ComboMouse = 5
};
/* End of enum PointingHidType Declaration */


/* Start of enum KeyboardHidType Declaration */
#  define KEYBOARDHIDTYPE_IID_STR "5a5b0996-3a3e-44bb-9019-56979812cbcc"
#  define KEYBOARDHIDTYPE_IID { \
    0x5a5b0996, 0x3a3e, 0x44bb, \
    { 0x90, 0x19, 0x56, 0x97, 0x98, 0x12, 0xcb, 0xcc } \
}
enum KeyboardHidType
{
    KeyboardHidType_None = 1,
    KeyboardHidType_PS2Keyboard = 2,
    KeyboardHidType_USBKeyboard = 3,
    KeyboardHidType_ComboKeyboard = 4
};
/* End of enum KeyboardHidType Declaration */


/* Start of enum VFSType Declaration */
#  define VFSTYPE_IID_STR "813999ba-b949-48a8-9230-aadc6285e2f2"
#  define VFSTYPE_IID { \
    0x813999ba, 0xb949, 0x48a8, \
    { 0x92, 0x30, 0xaa, 0xdc, 0x62, 0x85, 0xe2, 0xf2 } \
}
enum VFSType
{
    VFSType_File = 1,
    VFSType_Cloud = 2,
    VFSType_S3 = 3,
    VFSType_WebDav = 4
};
/* End of enum VFSType Declaration */


/* Start of enum VFSFileType Declaration */
#  define VFSFILETYPE_IID_STR "714333cd-44e2-415f-a245-d378fa9b1242"
#  define VFSFILETYPE_IID { \
    0x714333cd, 0x44e2, 0x415f, \
    { 0xa2, 0x45, 0xd3, 0x78, 0xfa, 0x9b, 0x12, 0x42 } \
}
enum VFSFileType
{
    VFSFileType_Unknown = 1,
    VFSFileType_Fifo = 2,
    VFSFileType_DevChar = 3,
    VFSFileType_Directory = 4,
    VFSFileType_DevBlock = 5,
    VFSFileType_File = 6,
    VFSFileType_SymLink = 7,
    VFSFileType_Socket = 8,
    VFSFileType_WhiteOut = 9
};
/* End of enum VFSFileType Declaration */


/* Start of enum VirtualSystemDescriptionType Declaration */
#  define VIRTUALSYSTEMDESCRIPTIONTYPE_IID_STR "c0f8f135-3a1d-417d-afa6-b38b95a91f90"
#  define VIRTUALSYSTEMDESCRIPTIONTYPE_IID { \
    0xc0f8f135, 0x3a1d, 0x417d, \
    { 0xaf, 0xa6, 0xb3, 0x8b, 0x95, 0xa9, 0x1f, 0x90 } \
}
enum VirtualSystemDescriptionType
{
    VirtualSystemDescriptionType_Ignore = 1,
    VirtualSystemDescriptionType_OS = 2,
    VirtualSystemDescriptionType_Name = 3,
    VirtualSystemDescriptionType_Product = 4,
    VirtualSystemDescriptionType_Vendor = 5,
    VirtualSystemDescriptionType_Version = 6,
    VirtualSystemDescriptionType_ProductUrl = 7,
    VirtualSystemDescriptionType_VendorUrl = 8,
    VirtualSystemDescriptionType_Description = 9,
    VirtualSystemDescriptionType_License = 10,
    VirtualSystemDescriptionType_Miscellaneous = 11,
    VirtualSystemDescriptionType_CPU = 12,
    VirtualSystemDescriptionType_Memory = 13,
    VirtualSystemDescriptionType_HardDiskControllerIDE = 14,
    VirtualSystemDescriptionType_HardDiskControllerSATA = 15,
    VirtualSystemDescriptionType_HardDiskControllerSCSI = 16,
    VirtualSystemDescriptionType_HardDiskControllerSAS = 17,
    VirtualSystemDescriptionType_HardDiskImage = 18,
    VirtualSystemDescriptionType_Floppy = 19,
    VirtualSystemDescriptionType_CDROM = 20,
    VirtualSystemDescriptionType_NetworkAdapter = 21,
    VirtualSystemDescriptionType_USBController = 22,
    VirtualSystemDescriptionType_SoundCard = 23
};
/* End of enum VirtualSystemDescriptionType Declaration */


/* Start of enum VirtualSystemDescriptionValueType Declaration */
#  define VIRTUALSYSTEMDESCRIPTIONVALUETYPE_IID_STR "56d9403f-3425-4118-9919-36f2a9b8c77c"
#  define VIRTUALSYSTEMDESCRIPTIONVALUETYPE_IID { \
    0x56d9403f, 0x3425, 0x4118, \
    { 0x99, 0x19, 0x36, 0xf2, 0xa9, 0xb8, 0xc7, 0x7c } \
}
enum VirtualSystemDescriptionValueType
{
    VirtualSystemDescriptionValueType_Reference = 1,
    VirtualSystemDescriptionValueType_Original = 2,
    VirtualSystemDescriptionValueType_Auto = 3,
    VirtualSystemDescriptionValueType_ExtraConfig = 4
};
/* End of enum VirtualSystemDescriptionValueType Declaration */


/* Start of enum CleanupMode Declaration */
#  define CLEANUPMODE_IID_STR "67897c50-7cca-47a9-83f6-ce8fd8eb5441"
#  define CLEANUPMODE_IID { \
    0x67897c50, 0x7cca, 0x47a9, \
    { 0x83, 0xf6, 0xce, 0x8f, 0xd8, 0xeb, 0x54, 0x41 } \
}
enum CleanupMode
{
    CleanupMode_UnregisterOnly = 1,
    CleanupMode_DetachAllReturnNone = 2,
    CleanupMode_DetachAllReturnHardDisksOnly = 3,
    CleanupMode_Full = 4
};
/* End of enum CleanupMode Declaration */


/* Start of enum HostNetworkInterfaceMediumType Declaration */
#  define HOSTNETWORKINTERFACEMEDIUMTYPE_IID_STR "1aa54aaf-2497-45a2-bfb1-8eb225e93d5b"
#  define HOSTNETWORKINTERFACEMEDIUMTYPE_IID { \
    0x1aa54aaf, 0x2497, 0x45a2, \
    { 0xbf, 0xb1, 0x8e, 0xb2, 0x25, 0xe9, 0x3d, 0x5b } \
}
enum HostNetworkInterfaceMediumType
{
    HostNetworkInterfaceMediumType_Unknown = 0,
    HostNetworkInterfaceMediumType_Ethernet = 1,
    HostNetworkInterfaceMediumType_PPP = 2,
    HostNetworkInterfaceMediumType_SLIP = 3
};
/* End of enum HostNetworkInterfaceMediumType Declaration */


/* Start of enum HostNetworkInterfaceStatus Declaration */
#  define HOSTNETWORKINTERFACESTATUS_IID_STR "CC474A69-2710-434B-8D99-C38E5D5A6F41"
#  define HOSTNETWORKINTERFACESTATUS_IID { \
    0xCC474A69, 0x2710, 0x434B, \
    { 0x8D, 0x99, 0xC3, 0x8E, 0x5D, 0x5A, 0x6F, 0x41 } \
}
enum HostNetworkInterfaceStatus
{
    HostNetworkInterfaceStatus_Unknown = 0,
    HostNetworkInterfaceStatus_Up = 1,
    HostNetworkInterfaceStatus_Down = 2
};
/* End of enum HostNetworkInterfaceStatus Declaration */


/* Start of enum HostNetworkInterfaceType Declaration */
#  define HOSTNETWORKINTERFACETYPE_IID_STR "67431b00-9946-48a2-bc02-b25c5919f4f3"
#  define HOSTNETWORKINTERFACETYPE_IID { \
    0x67431b00, 0x9946, 0x48a2, \
    { 0xbc, 0x02, 0xb2, 0x5c, 0x59, 0x19, 0xf4, 0xf3 } \
}
enum HostNetworkInterfaceType
{
    HostNetworkInterfaceType_Bridged = 1,
    HostNetworkInterfaceType_HostOnly = 2
};
/* End of enum HostNetworkInterfaceType Declaration */


/* Start of enum AdditionsRunLevelType Declaration */
#  define ADDITIONSRUNLEVELTYPE_IID_STR "a25417ee-a9dd-4f5b-b0dc-377860087754"
#  define ADDITIONSRUNLEVELTYPE_IID { \
    0xa25417ee, 0xa9dd, 0x4f5b, \
    { 0xb0, 0xdc, 0x37, 0x78, 0x60, 0x08, 0x77, 0x54 } \
}
enum AdditionsRunLevelType
{
    AdditionsRunLevelType_None = 0,
    AdditionsRunLevelType_System = 1,
    AdditionsRunLevelType_Userland = 2,
    AdditionsRunLevelType_Desktop = 3
};
/* End of enum AdditionsRunLevelType Declaration */


/* Start of enum AdditionsUpdateFlag Declaration */
#  define ADDITIONSUPDATEFLAG_IID_STR "726a818d-18d6-4389-94e8-3e9e6826171a"
#  define ADDITIONSUPDATEFLAG_IID { \
    0x726a818d, 0x18d6, 0x4389, \
    { 0x94, 0xe8, 0x3e, 0x9e, 0x68, 0x26, 0x17, 0x1a } \
}
enum AdditionsUpdateFlag
{
    AdditionsUpdateFlag_None = 0,
    AdditionsUpdateFlag_WaitForUpdateStartOnly = 1
};
/* End of enum AdditionsUpdateFlag Declaration */


/* Start of enum ExecuteProcessFlag Declaration */
#  define EXECUTEPROCESSFLAG_IID_STR "3258e8a5-ba0c-43d5-86b5-cf91405fddc0"
#  define EXECUTEPROCESSFLAG_IID { \
    0x3258e8a5, 0xba0c, 0x43d5, \
    { 0x86, 0xb5, 0xcf, 0x91, 0x40, 0x5f, 0xdd, 0xc0 } \
}
enum ExecuteProcessFlag
{
    ExecuteProcessFlag_None = 0,
    ExecuteProcessFlag_WaitForProcessStartOnly = 1,
    ExecuteProcessFlag_IgnoreOrphanedProcesses = 2,
    ExecuteProcessFlag_Hidden = 4
};
/* End of enum ExecuteProcessFlag Declaration */


/* Start of enum ProcessInputFlag Declaration */
#  define PROCESSINPUTFLAG_IID_STR "5d38c1dd-2604-4ddf-92e5-0c0cdd3bdbd5"
#  define PROCESSINPUTFLAG_IID { \
    0x5d38c1dd, 0x2604, 0x4ddf, \
    { 0x92, 0xe5, 0x0c, 0x0c, 0xdd, 0x3b, 0xdb, 0xd5 } \
}
enum ProcessInputFlag
{
    ProcessInputFlag_None = 0,
    ProcessInputFlag_EndOfFile = 1
};
/* End of enum ProcessInputFlag Declaration */


/* Start of enum CopyFileFlag Declaration */
#  define COPYFILEFLAG_IID_STR "23f79fdf-738a-493d-b80b-42d607c9b916"
#  define COPYFILEFLAG_IID { \
    0x23f79fdf, 0x738a, 0x493d, \
    { 0xb8, 0x0b, 0x42, 0xd6, 0x07, 0xc9, 0xb9, 0x16 } \
}
enum CopyFileFlag
{
    CopyFileFlag_None = 0,
    CopyFileFlag_Recursive = 1,
    CopyFileFlag_Update = 2,
    CopyFileFlag_FollowLinks = 4
};
/* End of enum CopyFileFlag Declaration */


/* Start of enum CreateDirectoryFlag Declaration */
#  define CREATEDIRECTORYFLAG_IID_STR "26ff5bdd-c81f-4304-857b-b8be5e3f9cd6"
#  define CREATEDIRECTORYFLAG_IID { \
    0x26ff5bdd, 0xc81f, 0x4304, \
    { 0x85, 0x7b, 0xb8, 0xbe, 0x5e, 0x3f, 0x9c, 0xd6 } \
}
enum CreateDirectoryFlag
{
    CreateDirectoryFlag_None = 0,
    CreateDirectoryFlag_Parents = 1
};
/* End of enum CreateDirectoryFlag Declaration */


/* Start of enum MediumState Declaration */
#  define MEDIUMSTATE_IID_STR "ef41e980-e012-43cd-9dea-479d4ef14d13"
#  define MEDIUMSTATE_IID { \
    0xef41e980, 0xe012, 0x43cd, \
    { 0x9d, 0xea, 0x47, 0x9d, 0x4e, 0xf1, 0x4d, 0x13 } \
}
enum MediumState
{
    MediumState_NotCreated = 0,
    MediumState_Created = 1,
    MediumState_LockedRead = 2,
    MediumState_LockedWrite = 3,
    MediumState_Inaccessible = 4,
    MediumState_Creating = 5,
    MediumState_Deleting = 6
};
/* End of enum MediumState Declaration */


/* Start of enum MediumType Declaration */
#  define MEDIUMTYPE_IID_STR "fe663fb5-c244-4e1b-9d81-c628b417dd04"
#  define MEDIUMTYPE_IID { \
    0xfe663fb5, 0xc244, 0x4e1b, \
    { 0x9d, 0x81, 0xc6, 0x28, 0xb4, 0x17, 0xdd, 0x04 } \
}
enum MediumType
{
    MediumType_Normal = 0,
    MediumType_Immutable = 1,
    MediumType_Writethrough = 2,
    MediumType_Shareable = 3,
    MediumType_Readonly = 4,
    MediumType_MultiAttach = 5
};
/* End of enum MediumType Declaration */


/* Start of enum MediumVariant Declaration */
#  define MEDIUMVARIANT_IID_STR "584ea502-143b-4ab0-ad14-d1028fdf0316"
#  define MEDIUMVARIANT_IID { \
    0x584ea502, 0x143b, 0x4ab0, \
    { 0xad, 0x14, 0xd1, 0x02, 0x8f, 0xdf, 0x03, 0x16 } \
}
enum MediumVariant
{
    MediumVariant_Standard = 0,
    MediumVariant_VmdkSplit2G = 0x01,
    MediumVariant_VmdkStreamOptimized = 0x04,
    MediumVariant_VmdkESX = 0x08,
    MediumVariant_Fixed = 0x10000,
    MediumVariant_Diff = 0x20000
};
/* End of enum MediumVariant Declaration */


/* Start of enum DataType Declaration */
#  define DATATYPE_IID_STR "d90ea51e-a3f1-4a01-beb1-c1723c0d3ba7"
#  define DATATYPE_IID { \
    0xd90ea51e, 0xa3f1, 0x4a01, \
    { 0xbe, 0xb1, 0xc1, 0x72, 0x3c, 0x0d, 0x3b, 0xa7 } \
}
enum DataType
{
    DataType_Int32 = 0,
    DataType_Int8 = 1,
    DataType_String = 2
};
/* End of enum DataType Declaration */


/* Start of enum DataFlags Declaration */
#  define DATAFLAGS_IID_STR "86884dcf-1d6b-4f1b-b4bf-f5aa44959d60"
#  define DATAFLAGS_IID { \
    0x86884dcf, 0x1d6b, 0x4f1b, \
    { 0xb4, 0xbf, 0xf5, 0xaa, 0x44, 0x95, 0x9d, 0x60 } \
}
enum DataFlags
{
    DataFlags_None = 0x00,
    DataFlags_Mandatory = 0x01,
    DataFlags_Expert = 0x02,
    DataFlags_Array = 0x04,
    DataFlags_FlagMask = 0x07
};
/* End of enum DataFlags Declaration */


/* Start of enum MediumFormatCapabilities Declaration */
#  define MEDIUMFORMATCAPABILITIES_IID_STR "7342ba79-7ce0-4d94-8f86-5ed5a185d9bd"
#  define MEDIUMFORMATCAPABILITIES_IID { \
    0x7342ba79, 0x7ce0, 0x4d94, \
    { 0x8f, 0x86, 0x5e, 0xd5, 0xa1, 0x85, 0xd9, 0xbd } \
}
enum MediumFormatCapabilities
{
    MediumFormatCapabilities_Uuid = 0x01,
    MediumFormatCapabilities_CreateFixed = 0x02,
    MediumFormatCapabilities_CreateDynamic = 0x04,
    MediumFormatCapabilities_CreateSplit2G = 0x08,
    MediumFormatCapabilities_Differencing = 0x10,
    MediumFormatCapabilities_Asynchronous = 0x20,
    MediumFormatCapabilities_File = 0x40,
    MediumFormatCapabilities_Properties = 0x80,
    MediumFormatCapabilities_TcpNetworking = 0x100,
    MediumFormatCapabilities_VFS = 0x200,
    MediumFormatCapabilities_CapabilityMask = 0x3FF
};
/* End of enum MediumFormatCapabilities Declaration */


/* Start of enum MouseButtonState Declaration */
#  define MOUSEBUTTONSTATE_IID_STR "9ee094b8-b28a-4d56-a166-973cb588d7f8"
#  define MOUSEBUTTONSTATE_IID { \
    0x9ee094b8, 0xb28a, 0x4d56, \
    { 0xa1, 0x66, 0x97, 0x3c, 0xb5, 0x88, 0xd7, 0xf8 } \
}
enum MouseButtonState
{
    MouseButtonState_LeftButton = 0x01,
    MouseButtonState_RightButton = 0x02,
    MouseButtonState_MiddleButton = 0x04,
    MouseButtonState_WheelUp = 0x08,
    MouseButtonState_WheelDown = 0x10,
    MouseButtonState_XButton1 = 0x20,
    MouseButtonState_XButton2 = 0x40,
    MouseButtonState_MouseStateMask = 0x7F
};
/* End of enum MouseButtonState Declaration */


/* Start of enum FramebufferPixelFormat Declaration */
#  define FRAMEBUFFERPIXELFORMAT_IID_STR "7acfd5ed-29e3-45e3-8136-73c9224f3d2d"
#  define FRAMEBUFFERPIXELFORMAT_IID { \
    0x7acfd5ed, 0x29e3, 0x45e3, \
    { 0x81, 0x36, 0x73, 0xc9, 0x22, 0x4f, 0x3d, 0x2d } \
}
enum FramebufferPixelFormat
{
    FramebufferPixelFormat_Opaque = 0,
    FramebufferPixelFormat_FOURCC_RGB = 0x32424752
};
/* End of enum FramebufferPixelFormat Declaration */


/* Start of enum NetworkAttachmentType Declaration */
#  define NETWORKATTACHMENTTYPE_IID_STR "44bce1ee-99f7-4e8e-89fc-80597fd9eeaf"
#  define NETWORKATTACHMENTTYPE_IID { \
    0x44bce1ee, 0x99f7, 0x4e8e, \
    { 0x89, 0xfc, 0x80, 0x59, 0x7f, 0xd9, 0xee, 0xaf } \
}
enum NetworkAttachmentType
{
    NetworkAttachmentType_Null = 0,
    NetworkAttachmentType_NAT = 1,
    NetworkAttachmentType_Bridged = 2,
    NetworkAttachmentType_Internal = 3,
    NetworkAttachmentType_HostOnly = 4,
    NetworkAttachmentType_VDE = 5
};
/* End of enum NetworkAttachmentType Declaration */


/* Start of enum NetworkAdapterType Declaration */
#  define NETWORKADAPTERTYPE_IID_STR "3c2281e4-d952-4e87-8c7d-24379cb6a81c"
#  define NETWORKADAPTERTYPE_IID { \
    0x3c2281e4, 0xd952, 0x4e87, \
    { 0x8c, 0x7d, 0x24, 0x37, 0x9c, 0xb6, 0xa8, 0x1c } \
}
enum NetworkAdapterType
{
    NetworkAdapterType_Null = 0,
    NetworkAdapterType_Am79C970A = 1,
    NetworkAdapterType_Am79C973 = 2,
    NetworkAdapterType_I82540EM = 3,
    NetworkAdapterType_I82543GC = 4,
    NetworkAdapterType_I82545EM = 5,
    NetworkAdapterType_Virtio = 6
};
/* End of enum NetworkAdapterType Declaration */


/* Start of enum PortMode Declaration */
#  define PORTMODE_IID_STR "533b5fe3-0185-4197-86a7-17e37dd39d76"
#  define PORTMODE_IID { \
    0x533b5fe3, 0x0185, 0x4197, \
    { 0x86, 0xa7, 0x17, 0xe3, 0x7d, 0xd3, 0x9d, 0x76 } \
}
enum PortMode
{
    PortMode_Disconnected = 0,
    PortMode_HostPipe = 1,
    PortMode_HostDevice = 2,
    PortMode_RawFile = 3
};
/* End of enum PortMode Declaration */


/* Start of enum USBDeviceState Declaration */
#  define USBDEVICESTATE_IID_STR "b99a2e65-67fb-4882-82fd-f3e5e8193ab4"
#  define USBDEVICESTATE_IID { \
    0xb99a2e65, 0x67fb, 0x4882, \
    { 0x82, 0xfd, 0xf3, 0xe5, 0xe8, 0x19, 0x3a, 0xb4 } \
}
enum USBDeviceState
{
    USBDeviceState_NotSupported = 0,
    USBDeviceState_Unavailable = 1,
    USBDeviceState_Busy = 2,
    USBDeviceState_Available = 3,
    USBDeviceState_Held = 4,
    USBDeviceState_Captured = 5
};
/* End of enum USBDeviceState Declaration */


/* Start of enum USBDeviceFilterAction Declaration */
#  define USBDEVICEFILTERACTION_IID_STR "cbc30a49-2f4e-43b5-9da6-121320475933"
#  define USBDEVICEFILTERACTION_IID { \
    0xcbc30a49, 0x2f4e, 0x43b5, \
    { 0x9d, 0xa6, 0x12, 0x13, 0x20, 0x47, 0x59, 0x33 } \
}
enum USBDeviceFilterAction
{
    USBDeviceFilterAction_Null = 0,
    USBDeviceFilterAction_Ignore = 1,
    USBDeviceFilterAction_Hold = 2
};
/* End of enum USBDeviceFilterAction Declaration */


/* Start of enum AudioDriverType Declaration */
#  define AUDIODRIVERTYPE_IID_STR "4bcc3d73-c2fe-40db-b72f-0c2ca9d68496"
#  define AUDIODRIVERTYPE_IID { \
    0x4bcc3d73, 0xc2fe, 0x40db, \
    { 0xb7, 0x2f, 0x0c, 0x2c, 0xa9, 0xd6, 0x84, 0x96 } \
}
enum AudioDriverType
{
    AudioDriverType_Null = 0,
    AudioDriverType_WinMM = 1,
    AudioDriverType_OSS = 2,
    AudioDriverType_ALSA = 3,
    AudioDriverType_DirectSound = 4,
    AudioDriverType_CoreAudio = 5,
    AudioDriverType_MMPM = 6,
    AudioDriverType_Pulse = 7,
    AudioDriverType_SolAudio = 8
};
/* End of enum AudioDriverType Declaration */


/* Start of enum AudioControllerType Declaration */
#  define AUDIOCONTROLLERTYPE_IID_STR "7afd395c-42c3-444e-8788-3ce80292f36c"
#  define AUDIOCONTROLLERTYPE_IID { \
    0x7afd395c, 0x42c3, 0x444e, \
    { 0x87, 0x88, 0x3c, 0xe8, 0x02, 0x92, 0xf3, 0x6c } \
}
enum AudioControllerType
{
    AudioControllerType_AC97 = 0,
    AudioControllerType_SB16 = 1,
    AudioControllerType_HDA = 2
};
/* End of enum AudioControllerType Declaration */


/* Start of enum AuthType Declaration */
#  define AUTHTYPE_IID_STR "7eef6ef6-98c2-4dc2-ab35-10d2b292028d"
#  define AUTHTYPE_IID { \
    0x7eef6ef6, 0x98c2, 0x4dc2, \
    { 0xab, 0x35, 0x10, 0xd2, 0xb2, 0x92, 0x02, 0x8d } \
}
enum AuthType
{
    AuthType_Null = 0,
    AuthType_External = 1,
    AuthType_Guest = 2
};
/* End of enum AuthType Declaration */


/* Start of enum StorageBus Declaration */
#  define STORAGEBUS_IID_STR "eee67ab3-668d-4ef5-91e0-7025fe4a0d7a"
#  define STORAGEBUS_IID { \
    0xeee67ab3, 0x668d, 0x4ef5, \
    { 0x91, 0xe0, 0x70, 0x25, 0xfe, 0x4a, 0x0d, 0x7a } \
}
enum StorageBus
{
    StorageBus_Null = 0,
    StorageBus_IDE = 1,
    StorageBus_SATA = 2,
    StorageBus_SCSI = 3,
    StorageBus_Floppy = 4,
    StorageBus_SAS = 5
};
/* End of enum StorageBus Declaration */


/* Start of enum StorageControllerType Declaration */
#  define STORAGECONTROLLERTYPE_IID_STR "8a412b8a-f43e-4456-bd37-b474f0879a58"
#  define STORAGECONTROLLERTYPE_IID { \
    0x8a412b8a, 0xf43e, 0x4456, \
    { 0xbd, 0x37, 0xb4, 0x74, 0xf0, 0x87, 0x9a, 0x58 } \
}
enum StorageControllerType
{
    StorageControllerType_Null = 0,
    StorageControllerType_LsiLogic = 1,
    StorageControllerType_BusLogic = 2,
    StorageControllerType_IntelAhci = 3,
    StorageControllerType_PIIX3 = 4,
    StorageControllerType_PIIX4 = 5,
    StorageControllerType_ICH6 = 6,
    StorageControllerType_I82078 = 7,
    StorageControllerType_LsiLogicSas = 8
};
/* End of enum StorageControllerType Declaration */


/* Start of enum ChipsetType Declaration */
#  define CHIPSETTYPE_IID_STR "8b4096a8-a7c3-4d3b-bbb1-05a0a51ec394"
#  define CHIPSETTYPE_IID { \
    0x8b4096a8, 0xa7c3, 0x4d3b, \
    { 0xbb, 0xb1, 0x05, 0xa0, 0xa5, 0x1e, 0xc3, 0x94 } \
}
enum ChipsetType
{
    ChipsetType_Null = 0,
    ChipsetType_PIIX3 = 1,
    ChipsetType_ICH9 = 2
};
/* End of enum ChipsetType Declaration */


/* Start of enum NATAliasMode Declaration */
#  define NATALIASMODE_IID_STR "67772168-50d9-11df-9669-7fb714ee4fa1"
#  define NATALIASMODE_IID { \
    0x67772168, 0x50d9, 0x11df, \
    { 0x96, 0x69, 0x7f, 0xb7, 0x14, 0xee, 0x4f, 0xa1 } \
}
enum NATAliasMode
{
    NATAliasMode_AliasLog = 0x1,
    NATAliasMode_AliasProxyOnly = 0x02,
    NATAliasMode_AliasUseSamePorts = 0x04
};
/* End of enum NATAliasMode Declaration */


/* Start of enum NATProtocol Declaration */
#  define NATPROTOCOL_IID_STR "e90164be-eb03-11de-94af-fff9b1c1b19f"
#  define NATPROTOCOL_IID { \
    0xe90164be, 0xeb03, 0x11de, \
    { 0x94, 0xaf, 0xff, 0xf9, 0xb1, 0xc1, 0xb1, 0x9f } \
}
enum NATProtocol
{
    NATProtocol_UDP = 0,
    NATProtocol_TCP = 1
};
/* End of enum NATProtocol Declaration */


/* Start of enum BandwidthGroupType Declaration */
#  define BANDWIDTHGROUPTYPE_IID_STR "1d92b67d-dc69-4be9-ad4c-93a01e1e0c8e"
#  define BANDWIDTHGROUPTYPE_IID { \
    0x1d92b67d, 0xdc69, 0x4be9, \
    { 0xad, 0x4c, 0x93, 0xa0, 0x1e, 0x1e, 0x0c, 0x8e } \
}
enum BandwidthGroupType
{
    BandwidthGroupType_Null = 0,
    BandwidthGroupType_Disk = 1,
    BandwidthGroupType_Network = 2
};
/* End of enum BandwidthGroupType Declaration */


/* Start of enum VBoxEventType Declaration */
#  define VBOXEVENTTYPE_IID_STR "e71c487f-755e-46e9-a476-dd6a5d134597"
#  define VBOXEVENTTYPE_IID { \
    0xe71c487f, 0x755e, 0x46e9, \
    { 0xa4, 0x76, 0xdd, 0x6a, 0x5d, 0x13, 0x45, 0x97 } \
}
enum VBoxEventType
{
    VBoxEventType_Invalid = 0,
    VBoxEventType_Any = 1,
    VBoxEventType_Vetoable = 2,
    VBoxEventType_MachineEvent = 3,
    VBoxEventType_SnapshotEvent = 4,
    VBoxEventType_InputEvent = 5,
    VBoxEventType_LastWildcard = 31,
    VBoxEventType_OnMachineStateChanged = 32,
    VBoxEventType_OnMachineDataChanged = 33,
    VBoxEventType_OnExtraDataChanged = 34,
    VBoxEventType_OnExtraDataCanChange = 35,
    VBoxEventType_OnMediumRegistered = 36,
    VBoxEventType_OnMachineRegistered = 37,
    VBoxEventType_OnSessionStateChanged = 38,
    VBoxEventType_OnSnapshotTaken = 39,
    VBoxEventType_OnSnapshotDeleted = 40,
    VBoxEventType_OnSnapshotChanged = 41,
    VBoxEventType_OnGuestPropertyChanged = 42,
    VBoxEventType_OnMousePointerShapeChanged = 43,
    VBoxEventType_OnMouseCapabilityChanged = 44,
    VBoxEventType_OnKeyboardLedsChanged = 45,
    VBoxEventType_OnStateChanged = 46,
    VBoxEventType_OnAdditionsStateChanged = 47,
    VBoxEventType_OnNetworkAdapterChanged = 48,
    VBoxEventType_OnSerialPortChanged = 49,
    VBoxEventType_OnParallelPortChanged = 50,
    VBoxEventType_OnStorageControllerChanged = 51,
    VBoxEventType_OnMediumChanged = 52,
    VBoxEventType_OnVRDEServerChanged = 53,
    VBoxEventType_OnUSBControllerChanged = 54,
    VBoxEventType_OnUSBDeviceStateChanged = 55,
    VBoxEventType_OnSharedFolderChanged = 56,
    VBoxEventType_OnRuntimeError = 57,
    VBoxEventType_OnCanShowWindow = 58,
    VBoxEventType_OnShowWindow = 59,
    VBoxEventType_OnCPUChanged = 60,
    VBoxEventType_OnVRDEServerInfoChanged = 61,
    VBoxEventType_OnEventSourceChanged = 62,
    VBoxEventType_OnCPUExecutionCapChanged = 63,
    VBoxEventType_OnGuestKeyboard = 64,
    VBoxEventType_OnGuestMouse = 65,
    VBoxEventType_OnNATRedirect = 66,
    VBoxEventType_OnHostPciDevicePlug = 67,
    VBoxEventType_OnVBoxSVCAvailabilityChanged = 68,
    VBoxEventType_OnBandwidthGroupChanged = 69,
    VBoxEventType_OnGuestMonitorChanged = 70,
    VBoxEventType_Last = 71
};
/* End of enum VBoxEventType Declaration */


/* Start of enum GuestMonitorChangedEventType Declaration */
#  define GUESTMONITORCHANGEDEVENTTYPE_IID_STR "ef172985-7e36-4297-95be-e46396968d66"
#  define GUESTMONITORCHANGEDEVENTTYPE_IID { \
    0xef172985, 0x7e36, 0x4297, \
    { 0x95, 0xbe, 0xe4, 0x63, 0x96, 0x96, 0x8d, 0x66 } \
}
enum GuestMonitorChangedEventType
{
    GuestMonitorChangedEventType_Enabled = 0,
    GuestMonitorChangedEventType_Disabled = 1,
    GuestMonitorChangedEventType_NewOrigin = 2
};
/* End of enum GuestMonitorChangedEventType Declaration */


/* Start of struct IVirtualBoxErrorInfo Declaration */
#  define IVIRTUALBOXERRORINFO_IID_STR "e053d3c0-f493-491b-a735-3a9f0b1feed4"
#  define IVIRTUALBOXERRORINFO_IID { \
    0xe053d3c0, 0xf493, 0x491b, \
    { 0xa7, 0x35, 0x3a, 0x9f, 0x0b, 0x1f, 0xee, 0xd4 } \
}
struct IVirtualBoxErrorInfo_vtbl
{
    struct nsIException_vtbl nsiexception;

    nsresult PR_COM_METHOD (*GetResultCode)(IVirtualBoxErrorInfo *pThis, PRInt32 *resultCode);

    nsresult PR_COM_METHOD (*GetInterfaceID)(IVirtualBoxErrorInfo *pThis, PRUnichar * *interfaceID);

    nsresult PR_COM_METHOD (*GetComponent)(IVirtualBoxErrorInfo *pThis, PRUnichar * *component);

    nsresult PR_COM_METHOD (*GetText)(IVirtualBoxErrorInfo *pThis, PRUnichar * *text);

    nsresult PR_COM_METHOD (*GetNext)(IVirtualBoxErrorInfo *pThis, IVirtualBoxErrorInfo * *next);

};

struct IVirtualBoxErrorInfo
{
    struct IVirtualBoxErrorInfo_vtbl *vtbl;
};
/* End of struct IVirtualBoxErrorInfo Declaration */


/* Start of struct IDHCPServer Declaration */
#  define IDHCPSERVER_IID_STR "6cfe387c-74fb-4ca7-bff6-973bec8af7a3"
#  define IDHCPSERVER_IID { \
    0x6cfe387c, 0x74fb, 0x4ca7, \
    { 0xbf, 0xf6, 0x97, 0x3b, 0xec, 0x8a, 0xf7, 0xa3 } \
}
struct IDHCPServer_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetEnabled)(IDHCPServer *pThis, PRBool *enabled);
    nsresult PR_COM_METHOD (*SetEnabled)(IDHCPServer *pThis, PRBool enabled);

    nsresult PR_COM_METHOD (*GetIPAddress)(IDHCPServer *pThis, PRUnichar * *IPAddress);

    nsresult PR_COM_METHOD (*GetNetworkMask)(IDHCPServer *pThis, PRUnichar * *networkMask);

    nsresult PR_COM_METHOD (*GetNetworkName)(IDHCPServer *pThis, PRUnichar * *networkName);

    nsresult PR_COM_METHOD (*GetLowerIP)(IDHCPServer *pThis, PRUnichar * *lowerIP);

    nsresult PR_COM_METHOD (*GetUpperIP)(IDHCPServer *pThis, PRUnichar * *upperIP);

    nsresult PR_COM_METHOD (*SetConfiguration)(
        IDHCPServer *pThis,
        PRUnichar * IPAddress,
        PRUnichar * networkMask,
        PRUnichar * FromIPAddress,
        PRUnichar * ToIPAddress
    );

    nsresult PR_COM_METHOD (*Start)(
        IDHCPServer *pThis,
        PRUnichar * networkName,
        PRUnichar * trunkName,
        PRUnichar * trunkType
    );

    nsresult PR_COM_METHOD (*Stop)(IDHCPServer *pThis );

};

struct IDHCPServer
{
    struct IDHCPServer_vtbl *vtbl;
};
/* End of struct IDHCPServer Declaration */


/* Start of struct IVirtualBox Declaration */
#  define IVIRTUALBOX_IID_STR "d2de270c-1d4b-4c9e-843f-bbb9b47269ff"
#  define IVIRTUALBOX_IID { \
    0xd2de270c, 0x1d4b, 0x4c9e, \
    { 0x84, 0x3f, 0xbb, 0xb9, 0xb4, 0x72, 0x69, 0xff } \
}
struct IVirtualBox_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetVersion)(IVirtualBox *pThis, PRUnichar * *version);

    nsresult PR_COM_METHOD (*GetRevision)(IVirtualBox *pThis, PRUint32 *revision);

    nsresult PR_COM_METHOD (*GetPackageType)(IVirtualBox *pThis, PRUnichar * *packageType);

    nsresult PR_COM_METHOD (*GetHomeFolder)(IVirtualBox *pThis, PRUnichar * *homeFolder);

    nsresult PR_COM_METHOD (*GetSettingsFilePath)(IVirtualBox *pThis, PRUnichar * *settingsFilePath);

    nsresult PR_COM_METHOD (*GetHost)(IVirtualBox *pThis, IHost * *host);

    nsresult PR_COM_METHOD (*GetSystemProperties)(IVirtualBox *pThis, ISystemProperties * *systemProperties);

    nsresult PR_COM_METHOD (*GetMachines)(IVirtualBox *pThis, PRUint32 *machinesSize, IMachine * **machines);

    nsresult PR_COM_METHOD (*GetHardDisks)(IVirtualBox *pThis, PRUint32 *hardDisksSize, IMedium * **hardDisks);

    nsresult PR_COM_METHOD (*GetDVDImages)(IVirtualBox *pThis, PRUint32 *DVDImagesSize, IMedium * **DVDImages);

    nsresult PR_COM_METHOD (*GetFloppyImages)(IVirtualBox *pThis, PRUint32 *floppyImagesSize, IMedium * **floppyImages);

    nsresult PR_COM_METHOD (*GetProgressOperations)(IVirtualBox *pThis, PRUint32 *progressOperationsSize, IProgress * **progressOperations);

    nsresult PR_COM_METHOD (*GetGuestOSTypes)(IVirtualBox *pThis, PRUint32 *guestOSTypesSize, IGuestOSType * **guestOSTypes);

    nsresult PR_COM_METHOD (*GetSharedFolders)(IVirtualBox *pThis, PRUint32 *sharedFoldersSize, ISharedFolder * **sharedFolders);

    nsresult PR_COM_METHOD (*GetPerformanceCollector)(IVirtualBox *pThis, IPerformanceCollector * *performanceCollector);

    nsresult PR_COM_METHOD (*GetDHCPServers)(IVirtualBox *pThis, PRUint32 *DHCPServersSize, IDHCPServer * **DHCPServers);

    nsresult PR_COM_METHOD (*GetEventSource)(IVirtualBox *pThis, IEventSource * *eventSource);

    nsresult PR_COM_METHOD (*GetExtensionPackManager)(IVirtualBox *pThis, IExtPackManager * *extensionPackManager);

    nsresult PR_COM_METHOD (*ComposeMachineFilename)(
        IVirtualBox *pThis,
        PRUnichar * name,
        PRUnichar * baseFolder,
        PRUnichar * * file
    );

    nsresult PR_COM_METHOD (*CreateMachine)(
        IVirtualBox *pThis,
        PRUnichar * settingsFile,
        PRUnichar * name,
        PRUnichar * osTypeId,
        PRUnichar * id,
        PRBool forceOverwrite,
        IMachine * * machine
    );

    nsresult PR_COM_METHOD (*OpenMachine)(
        IVirtualBox *pThis,
        PRUnichar * settingsFile,
        IMachine * * machine
    );

    nsresult PR_COM_METHOD (*RegisterMachine)(
        IVirtualBox *pThis,
        IMachine * machine
    );

    nsresult PR_COM_METHOD (*FindMachine)(
        IVirtualBox *pThis,
        PRUnichar * nameOrId,
        IMachine * * machine
    );

    nsresult PR_COM_METHOD (*CreateAppliance)(
        IVirtualBox *pThis,
        IAppliance * * appliance
    );

    nsresult PR_COM_METHOD (*CreateHardDisk)(
        IVirtualBox *pThis,
        PRUnichar * format,
        PRUnichar * location,
        IMedium * * medium
    );

    nsresult PR_COM_METHOD (*OpenMedium)(
        IVirtualBox *pThis,
        PRUnichar * location,
        PRUint32 deviceType,
        PRUint32 accessMode,
        IMedium * * medium
    );

    nsresult PR_COM_METHOD (*FindMedium)(
        IVirtualBox *pThis,
        PRUnichar * location,
        PRUint32 type,
        IMedium * * medium
    );

    nsresult PR_COM_METHOD (*GetGuestOSType)(
        IVirtualBox *pThis,
        PRUnichar * id,
        IGuestOSType * * type
    );

    nsresult PR_COM_METHOD (*CreateSharedFolder)(
        IVirtualBox *pThis,
        PRUnichar * name,
        PRUnichar * hostPath,
        PRBool writable,
        PRBool automount
    );

    nsresult PR_COM_METHOD (*RemoveSharedFolder)(
        IVirtualBox *pThis,
        PRUnichar * name
    );

    nsresult PR_COM_METHOD (*GetExtraDataKeys)(
        IVirtualBox *pThis,
        PRUint32 *valueSize,
        PRUnichar *** value
    );

    nsresult PR_COM_METHOD (*GetExtraData)(
        IVirtualBox *pThis,
        PRUnichar * key,
        PRUnichar * * value
    );

    nsresult PR_COM_METHOD (*SetExtraData)(
        IVirtualBox *pThis,
        PRUnichar * key,
        PRUnichar * value
    );

    nsresult PR_COM_METHOD (*CreateDHCPServer)(
        IVirtualBox *pThis,
        PRUnichar * name,
        IDHCPServer * * server
    );

    nsresult PR_COM_METHOD (*FindDHCPServerByNetworkName)(
        IVirtualBox *pThis,
        PRUnichar * name,
        IDHCPServer * * server
    );

    nsresult PR_COM_METHOD (*RemoveDHCPServer)(
        IVirtualBox *pThis,
        IDHCPServer * server
    );

    nsresult PR_COM_METHOD (*CheckFirmwarePresent)(
        IVirtualBox *pThis,
        PRUint32 firmwareType,
        PRUnichar * version,
        PRUnichar * * url,
        PRUnichar * * file,
        PRBool * result
    );

};

struct IVirtualBox
{
    struct IVirtualBox_vtbl *vtbl;
};
/* End of struct IVirtualBox Declaration */


/* Start of struct IVFSExplorer Declaration */
#  define IVFSEXPLORER_IID_STR "003d7f92-d38e-487f-b790-8c5e8631cb2f"
#  define IVFSEXPLORER_IID { \
    0x003d7f92, 0xd38e, 0x487f, \
    { 0xb7, 0x90, 0x8c, 0x5e, 0x86, 0x31, 0xcb, 0x2f } \
}
struct IVFSExplorer_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetPath)(IVFSExplorer *pThis, PRUnichar * *path);

    nsresult PR_COM_METHOD (*GetType)(IVFSExplorer *pThis, PRUint32 *type);

    nsresult PR_COM_METHOD (*Update)(
        IVFSExplorer *pThis,
        IProgress * * aProgress
    );

    nsresult PR_COM_METHOD (*Cd)(
        IVFSExplorer *pThis,
        PRUnichar * aDir,
        IProgress * * aProgress
    );

    nsresult PR_COM_METHOD (*CdUp)(
        IVFSExplorer *pThis,
        IProgress * * aProgress
    );

    nsresult PR_COM_METHOD (*EntryList)(
        IVFSExplorer *pThis,
        PRUint32 *aNamesSize,
        PRUnichar *** aNames,
        PRUint32 *aTypesSize,
        PRUint32* aTypes,
        PRUint32 *aSizesSize,
        PRUint32* aSizes,
        PRUint32 *aModesSize,
        PRUint32* aModes
    );

    nsresult PR_COM_METHOD (*Exists)(
        IVFSExplorer *pThis,
        PRUint32 aNamesSize,
        PRUnichar ** aNames,
        PRUint32 *aExistsSize,
        PRUnichar *** aExists
    );

    nsresult PR_COM_METHOD (*Remove)(
        IVFSExplorer *pThis,
        PRUint32 aNamesSize,
        PRUnichar ** aNames,
        IProgress * * aProgress
    );

};

struct IVFSExplorer
{
    struct IVFSExplorer_vtbl *vtbl;
};
/* End of struct IVFSExplorer Declaration */


/* Start of struct IAppliance Declaration */
#  define IAPPLIANCE_IID_STR "7b148032-4124-4f46-b56a-b48ac1273f5a"
#  define IAPPLIANCE_IID { \
    0x7b148032, 0x4124, 0x4f46, \
    { 0xb5, 0x6a, 0xb4, 0x8a, 0xc1, 0x27, 0x3f, 0x5a } \
}
struct IAppliance_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetPath)(IAppliance *pThis, PRUnichar * *path);

    nsresult PR_COM_METHOD (*GetDisks)(IAppliance *pThis, PRUint32 *disksSize, PRUnichar * **disks);

    nsresult PR_COM_METHOD (*GetVirtualSystemDescriptions)(IAppliance *pThis, PRUint32 *virtualSystemDescriptionsSize, IVirtualSystemDescription * **virtualSystemDescriptions);

    nsresult PR_COM_METHOD (*GetMachines)(IAppliance *pThis, PRUint32 *machinesSize, PRUnichar * **machines);

    nsresult PR_COM_METHOD (*Read)(
        IAppliance *pThis,
        PRUnichar * file,
        IProgress * * aProgress
    );

    nsresult PR_COM_METHOD (*Interpret)(IAppliance *pThis );

    nsresult PR_COM_METHOD (*ImportMachines)(
        IAppliance *pThis,
        IProgress * * aProgress
    );

    nsresult PR_COM_METHOD (*CreateVFSExplorer)(
        IAppliance *pThis,
        PRUnichar * aUri,
        IVFSExplorer * * aExplorer
    );

    nsresult PR_COM_METHOD (*Write)(
        IAppliance *pThis,
        PRUnichar * format,
        PRBool manifest,
        PRUnichar * path,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*GetWarnings)(
        IAppliance *pThis,
        PRUint32 *aWarningsSize,
        PRUnichar *** aWarnings
    );

};

struct IAppliance
{
    struct IAppliance_vtbl *vtbl;
};
/* End of struct IAppliance Declaration */


/* Start of struct IVirtualSystemDescription Declaration */
#  define IVIRTUALSYSTEMDESCRIPTION_IID_STR "d7525e6c-531a-4c51-8e04-41235083a3d8"
#  define IVIRTUALSYSTEMDESCRIPTION_IID { \
    0xd7525e6c, 0x531a, 0x4c51, \
    { 0x8e, 0x04, 0x41, 0x23, 0x50, 0x83, 0xa3, 0xd8 } \
}
struct IVirtualSystemDescription_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetCount)(IVirtualSystemDescription *pThis, PRUint32 *count);

    nsresult PR_COM_METHOD (*GetDescription)(
        IVirtualSystemDescription *pThis,
        PRUint32 *aTypesSize,
        PRUint32* aTypes,
        PRUint32 *aRefsSize,
        PRUnichar *** aRefs,
        PRUint32 *aOvfValuesSize,
        PRUnichar *** aOvfValues,
        PRUint32 *aVBoxValuesSize,
        PRUnichar *** aVBoxValues,
        PRUint32 *aExtraConfigValuesSize,
        PRUnichar *** aExtraConfigValues
    );

    nsresult PR_COM_METHOD (*GetDescriptionByType)(
        IVirtualSystemDescription *pThis,
        PRUint32 aType,
        PRUint32 *aTypesSize,
        PRUint32* aTypes,
        PRUint32 *aRefsSize,
        PRUnichar *** aRefs,
        PRUint32 *aOvfValuesSize,
        PRUnichar *** aOvfValues,
        PRUint32 *aVBoxValuesSize,
        PRUnichar *** aVBoxValues,
        PRUint32 *aExtraConfigValuesSize,
        PRUnichar *** aExtraConfigValues
    );

    nsresult PR_COM_METHOD (*GetValuesByType)(
        IVirtualSystemDescription *pThis,
        PRUint32 aType,
        PRUint32 aWhich,
        PRUint32 *aValuesSize,
        PRUnichar *** aValues
    );

    nsresult PR_COM_METHOD (*SetFinalValues)(
        IVirtualSystemDescription *pThis,
        PRUint32 aEnabledSize,
        PRBool* aEnabled,
        PRUint32 aVBoxValuesSize,
        PRUnichar ** aVBoxValues,
        PRUint32 aExtraConfigValuesSize,
        PRUnichar ** aExtraConfigValues
    );

    nsresult PR_COM_METHOD (*AddDescription)(
        IVirtualSystemDescription *pThis,
        PRUint32 aType,
        PRUnichar * aVBoxValue,
        PRUnichar * aExtraConfigValue
    );

};

struct IVirtualSystemDescription
{
    struct IVirtualSystemDescription_vtbl *vtbl;
};
/* End of struct IVirtualSystemDescription Declaration */


/* Start of struct IInternalMachineControl Declaration */
#  define IINTERNALMACHINECONTROL_IID_STR "476126af-e223-4490-a8a0-b1f1575be013"
#  define IINTERNALMACHINECONTROL_IID { \
    0x476126af, 0xe223, 0x4490, \
    { 0xa8, 0xa0, 0xb1, 0xf1, 0x57, 0x5b, 0xe0, 0x13 } \
}
struct IInternalMachineControl_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*SetRemoveSavedStateFile)(
        IInternalMachineControl *pThis,
        PRBool aRemove
    );

    nsresult PR_COM_METHOD (*UpdateState)(
        IInternalMachineControl *pThis,
        PRUint32 state
    );

    nsresult PR_COM_METHOD (*GetIPCId)(
        IInternalMachineControl *pThis,
        PRUnichar * * id
    );

    nsresult PR_COM_METHOD (*BeginPowerUp)(
        IInternalMachineControl *pThis,
        IProgress * aProgress
    );

    nsresult PR_COM_METHOD (*EndPowerUp)(
        IInternalMachineControl *pThis,
        PRInt32 result
    );

    nsresult PR_COM_METHOD (*RunUSBDeviceFilters)(
        IInternalMachineControl *pThis,
        IUSBDevice * device,
        PRBool * matched,
        PRUint32 * maskedInterfaces
    );

    nsresult PR_COM_METHOD (*CaptureUSBDevice)(
        IInternalMachineControl *pThis,
        PRUnichar * id
    );

    nsresult PR_COM_METHOD (*DetachUSBDevice)(
        IInternalMachineControl *pThis,
        PRUnichar * id,
        PRBool done
    );

    nsresult PR_COM_METHOD (*AutoCaptureUSBDevices)(IInternalMachineControl *pThis );

    nsresult PR_COM_METHOD (*DetachAllUSBDevices)(
        IInternalMachineControl *pThis,
        PRBool done
    );

    nsresult PR_COM_METHOD (*OnSessionEnd)(
        IInternalMachineControl *pThis,
        ISession * session,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*BeginSavingState)(
        IInternalMachineControl *pThis,
        IProgress * * progress,
        PRUnichar * * stateFilePath
    );

    nsresult PR_COM_METHOD (*EndSavingState)(
        IInternalMachineControl *pThis,
        PRInt32 result,
        PRUnichar * errMsg
    );

    nsresult PR_COM_METHOD (*AdoptSavedState)(
        IInternalMachineControl *pThis,
        PRUnichar * savedStateFile
    );

    nsresult PR_COM_METHOD (*BeginTakingSnapshot)(
        IInternalMachineControl *pThis,
        IConsole * initiator,
        PRUnichar * name,
        PRUnichar * description,
        IProgress * consoleProgress,
        PRBool fTakingSnapshotOnline,
        PRUnichar * * stateFilePath
    );

    nsresult PR_COM_METHOD (*EndTakingSnapshot)(
        IInternalMachineControl *pThis,
        PRBool success
    );

    nsresult PR_COM_METHOD (*DeleteSnapshot)(
        IInternalMachineControl *pThis,
        IConsole * initiator,
        PRUnichar * id,
        PRUint32 * machineState,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*FinishOnlineMergeMedium)(
        IInternalMachineControl *pThis,
        IMediumAttachment * mediumAttachment,
        IMedium * source,
        IMedium * target,
        PRBool mergeForward,
        IMedium * parentForTarget,
        PRUint32 childrenToReparentSize,
        IMedium ** childrenToReparent
    );

    nsresult PR_COM_METHOD (*RestoreSnapshot)(
        IInternalMachineControl *pThis,
        IConsole * initiator,
        ISnapshot * snapshot,
        PRUint32 * machineState,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*PullGuestProperties)(
        IInternalMachineControl *pThis,
        PRUint32 *nameSize,
        PRUnichar *** name,
        PRUint32 *valueSize,
        PRUnichar *** value,
        PRUint32 *timestampSize,
        PRInt64* timestamp,
        PRUint32 *flagsSize,
        PRUnichar *** flags
    );

    nsresult PR_COM_METHOD (*PushGuestProperty)(
        IInternalMachineControl *pThis,
        PRUnichar * name,
        PRUnichar * value,
        PRInt64 timestamp,
        PRUnichar * flags
    );

    nsresult PR_COM_METHOD (*LockMedia)(IInternalMachineControl *pThis );

    nsresult PR_COM_METHOD (*UnlockMedia)(IInternalMachineControl *pThis );

};

struct IInternalMachineControl
{
    struct IInternalMachineControl_vtbl *vtbl;
};
/* End of struct IInternalMachineControl Declaration */


/* Start of struct IBIOSSettings Declaration */
#  define IBIOSSETTINGS_IID_STR "38b54279-dc35-4f5e-a431-835b867c6b5e"
#  define IBIOSSETTINGS_IID { \
    0x38b54279, 0xdc35, 0x4f5e, \
    { 0xa4, 0x31, 0x83, 0x5b, 0x86, 0x7c, 0x6b, 0x5e } \
}
struct IBIOSSettings_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetLogoFadeIn)(IBIOSSettings *pThis, PRBool *logoFadeIn);
    nsresult PR_COM_METHOD (*SetLogoFadeIn)(IBIOSSettings *pThis, PRBool logoFadeIn);

    nsresult PR_COM_METHOD (*GetLogoFadeOut)(IBIOSSettings *pThis, PRBool *logoFadeOut);
    nsresult PR_COM_METHOD (*SetLogoFadeOut)(IBIOSSettings *pThis, PRBool logoFadeOut);

    nsresult PR_COM_METHOD (*GetLogoDisplayTime)(IBIOSSettings *pThis, PRUint32 *logoDisplayTime);
    nsresult PR_COM_METHOD (*SetLogoDisplayTime)(IBIOSSettings *pThis, PRUint32 logoDisplayTime);

    nsresult PR_COM_METHOD (*GetLogoImagePath)(IBIOSSettings *pThis, PRUnichar * *logoImagePath);
    nsresult PR_COM_METHOD (*SetLogoImagePath)(IBIOSSettings *pThis, PRUnichar * logoImagePath);

    nsresult PR_COM_METHOD (*GetBootMenuMode)(IBIOSSettings *pThis, PRUint32 *bootMenuMode);
    nsresult PR_COM_METHOD (*SetBootMenuMode)(IBIOSSettings *pThis, PRUint32 bootMenuMode);

    nsresult PR_COM_METHOD (*GetACPIEnabled)(IBIOSSettings *pThis, PRBool *ACPIEnabled);
    nsresult PR_COM_METHOD (*SetACPIEnabled)(IBIOSSettings *pThis, PRBool ACPIEnabled);

    nsresult PR_COM_METHOD (*GetIOAPICEnabled)(IBIOSSettings *pThis, PRBool *IOAPICEnabled);
    nsresult PR_COM_METHOD (*SetIOAPICEnabled)(IBIOSSettings *pThis, PRBool IOAPICEnabled);

    nsresult PR_COM_METHOD (*GetTimeOffset)(IBIOSSettings *pThis, PRInt64 *timeOffset);
    nsresult PR_COM_METHOD (*SetTimeOffset)(IBIOSSettings *pThis, PRInt64 timeOffset);

    nsresult PR_COM_METHOD (*GetPXEDebugEnabled)(IBIOSSettings *pThis, PRBool *PXEDebugEnabled);
    nsresult PR_COM_METHOD (*SetPXEDebugEnabled)(IBIOSSettings *pThis, PRBool PXEDebugEnabled);

};

struct IBIOSSettings
{
    struct IBIOSSettings_vtbl *vtbl;
};
/* End of struct IBIOSSettings Declaration */


/* Start of struct IEventContext Declaration */
#  define IEVENTCONTEXT_IID_STR "7563F4E7-1583-40F7-B4C4-C9BA02CB0AE3"
#  define IEVENTCONTEXT_IID { \
    0x7563F4E7, 0x1583, 0x40F7, \
    { 0xB4, 0xC4, 0xC9, 0xBA, 0x02, 0xCB, 0x0A, 0xE3 } \
}
struct IEventContext_vtbl
{
    struct nsISupports_vtbl nsisupports;

};

struct IEventContext
{
    struct IEventContext_vtbl *vtbl;
};
/* End of struct IEventContext Declaration */


/* Start of struct IPciAddress Declaration */
#  define IPCIADDRESS_IID_STR "D88B324F-DB19-4D3B-A1A9-BF5B127199A8"
#  define IPCIADDRESS_IID { \
    0xD88B324F, 0xDB19, 0x4D3B, \
    { 0xA1, 0xA9, 0xBF, 0x5B, 0x12, 0x71, 0x99, 0xA8 } \
}
struct IPciAddress_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetBus)(IPciAddress *pThis, PRInt16 *bus);
    nsresult PR_COM_METHOD (*SetBus)(IPciAddress *pThis, PRInt16 bus);

    nsresult PR_COM_METHOD (*GetDevice)(IPciAddress *pThis, PRInt16 *device);
    nsresult PR_COM_METHOD (*SetDevice)(IPciAddress *pThis, PRInt16 device);

    nsresult PR_COM_METHOD (*GetDevFunction)(IPciAddress *pThis, PRInt16 *devFunction);
    nsresult PR_COM_METHOD (*SetDevFunction)(IPciAddress *pThis, PRInt16 devFunction);

    nsresult PR_COM_METHOD (*AsLong)(
        IPciAddress *pThis,
        PRInt32 * result
    );

    nsresult PR_COM_METHOD (*FromLong)(
        IPciAddress *pThis,
        PRInt32 number
    );

};

struct IPciAddress
{
    struct IPciAddress_vtbl *vtbl;
};
/* End of struct IPciAddress Declaration */


/* Start of struct IPciDeviceAttachment Declaration */
#  define IPCIDEVICEATTACHMENT_IID_STR "91f33d6f-e621-4f70-a77e-15f0e3c714d5"
#  define IPCIDEVICEATTACHMENT_IID { \
    0x91f33d6f, 0xe621, 0x4f70, \
    { 0xa7, 0x7e, 0x15, 0xf0, 0xe3, 0xc7, 0x14, 0xd5 } \
}
struct IPciDeviceAttachment_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetName)(IPciDeviceAttachment *pThis, PRUnichar * *name);

    nsresult PR_COM_METHOD (*GetIsPhysicalDevice)(IPciDeviceAttachment *pThis, PRBool *isPhysicalDevice);

    nsresult PR_COM_METHOD (*GetHostAddress)(IPciDeviceAttachment *pThis, PRInt32 *hostAddress);

    nsresult PR_COM_METHOD (*GetGuestAddress)(IPciDeviceAttachment *pThis, PRInt32 *guestAddress);

};

struct IPciDeviceAttachment
{
    struct IPciDeviceAttachment_vtbl *vtbl;
};
/* End of struct IPciDeviceAttachment Declaration */


/* Start of struct IMachine Declaration */
#  define IMACHINE_IID_STR "662c175e-a69d-40b8-a77a-1d719d0ab062"
#  define IMACHINE_IID { \
    0x662c175e, 0xa69d, 0x40b8, \
    { 0xa7, 0x7a, 0x1d, 0x71, 0x9d, 0x0a, 0xb0, 0x62 } \
}
struct IMachine_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetParent)(IMachine *pThis, IVirtualBox * *parent);

    nsresult PR_COM_METHOD (*GetAccessible)(IMachine *pThis, PRBool *accessible);

    nsresult PR_COM_METHOD (*GetAccessError)(IMachine *pThis, IVirtualBoxErrorInfo * *accessError);

    nsresult PR_COM_METHOD (*GetName)(IMachine *pThis, PRUnichar * *name);
    nsresult PR_COM_METHOD (*SetName)(IMachine *pThis, PRUnichar * name);

    nsresult PR_COM_METHOD (*GetDescription)(IMachine *pThis, PRUnichar * *description);
    nsresult PR_COM_METHOD (*SetDescription)(IMachine *pThis, PRUnichar * description);

    nsresult PR_COM_METHOD (*GetId)(IMachine *pThis, PRUnichar * *id);

    nsresult PR_COM_METHOD (*GetOSTypeId)(IMachine *pThis, PRUnichar * *OSTypeId);
    nsresult PR_COM_METHOD (*SetOSTypeId)(IMachine *pThis, PRUnichar * OSTypeId);

    nsresult PR_COM_METHOD (*GetHardwareVersion)(IMachine *pThis, PRUnichar * *HardwareVersion);
    nsresult PR_COM_METHOD (*SetHardwareVersion)(IMachine *pThis, PRUnichar * HardwareVersion);

    nsresult PR_COM_METHOD (*GetHardwareUUID)(IMachine *pThis, PRUnichar * *hardwareUUID);
    nsresult PR_COM_METHOD (*SetHardwareUUID)(IMachine *pThis, PRUnichar * hardwareUUID);

    nsresult PR_COM_METHOD (*GetCPUCount)(IMachine *pThis, PRUint32 *CPUCount);
    nsresult PR_COM_METHOD (*SetCPUCount)(IMachine *pThis, PRUint32 CPUCount);

    nsresult PR_COM_METHOD (*GetCPUHotPlugEnabled)(IMachine *pThis, PRBool *CPUHotPlugEnabled);
    nsresult PR_COM_METHOD (*SetCPUHotPlugEnabled)(IMachine *pThis, PRBool CPUHotPlugEnabled);

    nsresult PR_COM_METHOD (*GetCPUExecutionCap)(IMachine *pThis, PRUint32 *CPUExecutionCap);
    nsresult PR_COM_METHOD (*SetCPUExecutionCap)(IMachine *pThis, PRUint32 CPUExecutionCap);

    nsresult PR_COM_METHOD (*GetMemorySize)(IMachine *pThis, PRUint32 *memorySize);
    nsresult PR_COM_METHOD (*SetMemorySize)(IMachine *pThis, PRUint32 memorySize);

    nsresult PR_COM_METHOD (*GetMemoryBalloonSize)(IMachine *pThis, PRUint32 *memoryBalloonSize);
    nsresult PR_COM_METHOD (*SetMemoryBalloonSize)(IMachine *pThis, PRUint32 memoryBalloonSize);

    nsresult PR_COM_METHOD (*GetPageFusionEnabled)(IMachine *pThis, PRBool *PageFusionEnabled);
    nsresult PR_COM_METHOD (*SetPageFusionEnabled)(IMachine *pThis, PRBool PageFusionEnabled);

    nsresult PR_COM_METHOD (*GetVRAMSize)(IMachine *pThis, PRUint32 *VRAMSize);
    nsresult PR_COM_METHOD (*SetVRAMSize)(IMachine *pThis, PRUint32 VRAMSize);

    nsresult PR_COM_METHOD (*GetAccelerate3DEnabled)(IMachine *pThis, PRBool *accelerate3DEnabled);
    nsresult PR_COM_METHOD (*SetAccelerate3DEnabled)(IMachine *pThis, PRBool accelerate3DEnabled);

    nsresult PR_COM_METHOD (*GetAccelerate2DVideoEnabled)(IMachine *pThis, PRBool *accelerate2DVideoEnabled);
    nsresult PR_COM_METHOD (*SetAccelerate2DVideoEnabled)(IMachine *pThis, PRBool accelerate2DVideoEnabled);

    nsresult PR_COM_METHOD (*GetMonitorCount)(IMachine *pThis, PRUint32 *monitorCount);
    nsresult PR_COM_METHOD (*SetMonitorCount)(IMachine *pThis, PRUint32 monitorCount);

    nsresult PR_COM_METHOD (*GetBIOSSettings)(IMachine *pThis, IBIOSSettings * *BIOSSettings);

    nsresult PR_COM_METHOD (*GetFirmwareType)(IMachine *pThis, PRUint32 *firmwareType);
    nsresult PR_COM_METHOD (*SetFirmwareType)(IMachine *pThis, PRUint32 firmwareType);

    nsresult PR_COM_METHOD (*GetPointingHidType)(IMachine *pThis, PRUint32 *pointingHidType);
    nsresult PR_COM_METHOD (*SetPointingHidType)(IMachine *pThis, PRUint32 pointingHidType);

    nsresult PR_COM_METHOD (*GetKeyboardHidType)(IMachine *pThis, PRUint32 *keyboardHidType);
    nsresult PR_COM_METHOD (*SetKeyboardHidType)(IMachine *pThis, PRUint32 keyboardHidType);

    nsresult PR_COM_METHOD (*GetHpetEnabled)(IMachine *pThis, PRBool *hpetEnabled);
    nsresult PR_COM_METHOD (*SetHpetEnabled)(IMachine *pThis, PRBool hpetEnabled);

    nsresult PR_COM_METHOD (*GetChipsetType)(IMachine *pThis, PRUint32 *chipsetType);
    nsresult PR_COM_METHOD (*SetChipsetType)(IMachine *pThis, PRUint32 chipsetType);

    nsresult PR_COM_METHOD (*GetSnapshotFolder)(IMachine *pThis, PRUnichar * *snapshotFolder);
    nsresult PR_COM_METHOD (*SetSnapshotFolder)(IMachine *pThis, PRUnichar * snapshotFolder);

    nsresult PR_COM_METHOD (*GetVRDEServer)(IMachine *pThis, IVRDEServer * *VRDEServer);

    nsresult PR_COM_METHOD (*GetMediumAttachments)(IMachine *pThis, PRUint32 *mediumAttachmentsSize, IMediumAttachment * **mediumAttachments);

    nsresult PR_COM_METHOD (*GetUSBController)(IMachine *pThis, IUSBController * *USBController);

    nsresult PR_COM_METHOD (*GetAudioAdapter)(IMachine *pThis, IAudioAdapter * *audioAdapter);

    nsresult PR_COM_METHOD (*GetStorageControllers)(IMachine *pThis, PRUint32 *storageControllersSize, IStorageController * **storageControllers);

    nsresult PR_COM_METHOD (*GetSettingsFilePath)(IMachine *pThis, PRUnichar * *settingsFilePath);

    nsresult PR_COM_METHOD (*GetSettingsModified)(IMachine *pThis, PRBool *settingsModified);

    nsresult PR_COM_METHOD (*GetSessionState)(IMachine *pThis, PRUint32 *sessionState);

    nsresult PR_COM_METHOD (*GetSessionType)(IMachine *pThis, PRUnichar * *sessionType);

    nsresult PR_COM_METHOD (*GetSessionPid)(IMachine *pThis, PRUint32 *sessionPid);

    nsresult PR_COM_METHOD (*GetState)(IMachine *pThis, PRUint32 *state);

    nsresult PR_COM_METHOD (*GetLastStateChange)(IMachine *pThis, PRInt64 *lastStateChange);

    nsresult PR_COM_METHOD (*GetStateFilePath)(IMachine *pThis, PRUnichar * *stateFilePath);

    nsresult PR_COM_METHOD (*GetLogFolder)(IMachine *pThis, PRUnichar * *logFolder);

    nsresult PR_COM_METHOD (*GetCurrentSnapshot)(IMachine *pThis, ISnapshot * *currentSnapshot);

    nsresult PR_COM_METHOD (*GetSnapshotCount)(IMachine *pThis, PRUint32 *snapshotCount);

    nsresult PR_COM_METHOD (*GetCurrentStateModified)(IMachine *pThis, PRBool *currentStateModified);

    nsresult PR_COM_METHOD (*GetSharedFolders)(IMachine *pThis, PRUint32 *sharedFoldersSize, ISharedFolder * **sharedFolders);

    nsresult PR_COM_METHOD (*GetClipboardMode)(IMachine *pThis, PRUint32 *clipboardMode);
    nsresult PR_COM_METHOD (*SetClipboardMode)(IMachine *pThis, PRUint32 clipboardMode);

    nsresult PR_COM_METHOD (*GetGuestPropertyNotificationPatterns)(IMachine *pThis, PRUnichar * *guestPropertyNotificationPatterns);
    nsresult PR_COM_METHOD (*SetGuestPropertyNotificationPatterns)(IMachine *pThis, PRUnichar * guestPropertyNotificationPatterns);

    nsresult PR_COM_METHOD (*GetTeleporterEnabled)(IMachine *pThis, PRBool *teleporterEnabled);
    nsresult PR_COM_METHOD (*SetTeleporterEnabled)(IMachine *pThis, PRBool teleporterEnabled);

    nsresult PR_COM_METHOD (*GetTeleporterPort)(IMachine *pThis, PRUint32 *teleporterPort);
    nsresult PR_COM_METHOD (*SetTeleporterPort)(IMachine *pThis, PRUint32 teleporterPort);

    nsresult PR_COM_METHOD (*GetTeleporterAddress)(IMachine *pThis, PRUnichar * *teleporterAddress);
    nsresult PR_COM_METHOD (*SetTeleporterAddress)(IMachine *pThis, PRUnichar * teleporterAddress);

    nsresult PR_COM_METHOD (*GetTeleporterPassword)(IMachine *pThis, PRUnichar * *teleporterPassword);
    nsresult PR_COM_METHOD (*SetTeleporterPassword)(IMachine *pThis, PRUnichar * teleporterPassword);

    nsresult PR_COM_METHOD (*GetFaultToleranceState)(IMachine *pThis, PRUint32 *faultToleranceState);
    nsresult PR_COM_METHOD (*SetFaultToleranceState)(IMachine *pThis, PRUint32 faultToleranceState);

    nsresult PR_COM_METHOD (*GetFaultTolerancePort)(IMachine *pThis, PRUint32 *faultTolerancePort);
    nsresult PR_COM_METHOD (*SetFaultTolerancePort)(IMachine *pThis, PRUint32 faultTolerancePort);

    nsresult PR_COM_METHOD (*GetFaultToleranceAddress)(IMachine *pThis, PRUnichar * *faultToleranceAddress);
    nsresult PR_COM_METHOD (*SetFaultToleranceAddress)(IMachine *pThis, PRUnichar * faultToleranceAddress);

    nsresult PR_COM_METHOD (*GetFaultTolerancePassword)(IMachine *pThis, PRUnichar * *faultTolerancePassword);
    nsresult PR_COM_METHOD (*SetFaultTolerancePassword)(IMachine *pThis, PRUnichar * faultTolerancePassword);

    nsresult PR_COM_METHOD (*GetFaultToleranceSyncInterval)(IMachine *pThis, PRUint32 *faultToleranceSyncInterval);
    nsresult PR_COM_METHOD (*SetFaultToleranceSyncInterval)(IMachine *pThis, PRUint32 faultToleranceSyncInterval);

    nsresult PR_COM_METHOD (*GetRTCUseUTC)(IMachine *pThis, PRBool *RTCUseUTC);
    nsresult PR_COM_METHOD (*SetRTCUseUTC)(IMachine *pThis, PRBool RTCUseUTC);

    nsresult PR_COM_METHOD (*GetIoCacheEnabled)(IMachine *pThis, PRBool *ioCacheEnabled);
    nsresult PR_COM_METHOD (*SetIoCacheEnabled)(IMachine *pThis, PRBool ioCacheEnabled);

    nsresult PR_COM_METHOD (*GetIoCacheSize)(IMachine *pThis, PRUint32 *ioCacheSize);
    nsresult PR_COM_METHOD (*SetIoCacheSize)(IMachine *pThis, PRUint32 ioCacheSize);

    nsresult PR_COM_METHOD (*GetBandwidthControl)(IMachine *pThis, IBandwidthControl * *bandwidthControl);

    nsresult PR_COM_METHOD (*GetPciDeviceAssignments)(IMachine *pThis, PRUint32 *pciDeviceAssignmentsSize, IPciDeviceAttachment * **pciDeviceAssignments);

    nsresult PR_COM_METHOD (*LockMachine)(
        IMachine *pThis,
        ISession * session,
        PRUint32 lockType
    );

    nsresult PR_COM_METHOD (*LaunchVMProcess)(
        IMachine *pThis,
        ISession * session,
        PRUnichar * type,
        PRUnichar * environment,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*SetBootOrder)(
        IMachine *pThis,
        PRUint32 position,
        PRUint32 device
    );

    nsresult PR_COM_METHOD (*GetBootOrder)(
        IMachine *pThis,
        PRUint32 position,
        PRUint32 * device
    );

    nsresult PR_COM_METHOD (*AttachDevice)(
        IMachine *pThis,
        PRUnichar * name,
        PRInt32 controllerPort,
        PRInt32 device,
        PRUint32 type,
        IMedium * medium
    );

    nsresult PR_COM_METHOD (*DetachDevice)(
        IMachine *pThis,
        PRUnichar * name,
        PRInt32 controllerPort,
        PRInt32 device
    );

    nsresult PR_COM_METHOD (*PassthroughDevice)(
        IMachine *pThis,
        PRUnichar * name,
        PRInt32 controllerPort,
        PRInt32 device,
        PRBool passthrough
    );

    nsresult PR_COM_METHOD (*SetBandwidthGroupForDevice)(
        IMachine *pThis,
        PRUnichar * name,
        PRInt32 controllerPort,
        PRInt32 device,
        IBandwidthGroup * bandwidthGroup
    );

    nsresult PR_COM_METHOD (*MountMedium)(
        IMachine *pThis,
        PRUnichar * name,
        PRInt32 controllerPort,
        PRInt32 device,
        IMedium * medium,
        PRBool force
    );

    nsresult PR_COM_METHOD (*GetMedium)(
        IMachine *pThis,
        PRUnichar * name,
        PRInt32 controllerPort,
        PRInt32 device,
        IMedium * * medium
    );

    nsresult PR_COM_METHOD (*GetMediumAttachmentsOfController)(
        IMachine *pThis,
        PRUnichar * name,
        PRUint32 *mediumAttachmentsSize,
        IMediumAttachment *** mediumAttachments
    );

    nsresult PR_COM_METHOD (*GetMediumAttachment)(
        IMachine *pThis,
        PRUnichar * name,
        PRInt32 controllerPort,
        PRInt32 device,
        IMediumAttachment * * attachment
    );

    nsresult PR_COM_METHOD (*AttachHostPciDevice)(
        IMachine *pThis,
        PRInt32 hostAddress,
        PRInt32 desiredGuestAddress,
        IEventContext * eventContext,
        PRBool tryToUnbind
    );

    nsresult PR_COM_METHOD (*DetachHostPciDevice)(
        IMachine *pThis,
        PRInt32 hostAddress
    );

    nsresult PR_COM_METHOD (*GetNetworkAdapter)(
        IMachine *pThis,
        PRUint32 slot,
        INetworkAdapter * * adapter
    );

    nsresult PR_COM_METHOD (*AddStorageController)(
        IMachine *pThis,
        PRUnichar * name,
        PRUint32 connectionType,
        IStorageController * * controller
    );

    nsresult PR_COM_METHOD (*GetStorageControllerByName)(
        IMachine *pThis,
        PRUnichar * name,
        IStorageController * * storageController
    );

    nsresult PR_COM_METHOD (*GetStorageControllerByInstance)(
        IMachine *pThis,
        PRUint32 instance,
        IStorageController * * storageController
    );

    nsresult PR_COM_METHOD (*RemoveStorageController)(
        IMachine *pThis,
        PRUnichar * name
    );

    nsresult PR_COM_METHOD (*SetStorageControllerBootable)(
        IMachine *pThis,
        PRUnichar * name,
        PRBool bootable
    );

    nsresult PR_COM_METHOD (*GetSerialPort)(
        IMachine *pThis,
        PRUint32 slot,
        ISerialPort * * port
    );

    nsresult PR_COM_METHOD (*GetParallelPort)(
        IMachine *pThis,
        PRUint32 slot,
        IParallelPort * * port
    );

    nsresult PR_COM_METHOD (*GetExtraDataKeys)(
        IMachine *pThis,
        PRUint32 *valueSize,
        PRUnichar *** value
    );

    nsresult PR_COM_METHOD (*GetExtraData)(
        IMachine *pThis,
        PRUnichar * key,
        PRUnichar * * value
    );

    nsresult PR_COM_METHOD (*SetExtraData)(
        IMachine *pThis,
        PRUnichar * key,
        PRUnichar * value
    );

    nsresult PR_COM_METHOD (*GetCPUProperty)(
        IMachine *pThis,
        PRUint32 property,
        PRBool * value
    );

    nsresult PR_COM_METHOD (*SetCPUProperty)(
        IMachine *pThis,
        PRUint32 property,
        PRBool value
    );

    nsresult PR_COM_METHOD (*GetCPUIDLeaf)(
        IMachine *pThis,
        PRUint32 id,
        PRUint32 * valEax,
        PRUint32 * valEbx,
        PRUint32 * valEcx,
        PRUint32 * valEdx
    );

    nsresult PR_COM_METHOD (*SetCPUIDLeaf)(
        IMachine *pThis,
        PRUint32 id,
        PRUint32 valEax,
        PRUint32 valEbx,
        PRUint32 valEcx,
        PRUint32 valEdx
    );

    nsresult PR_COM_METHOD (*RemoveCPUIDLeaf)(
        IMachine *pThis,
        PRUint32 id
    );

    nsresult PR_COM_METHOD (*RemoveAllCPUIDLeaves)(IMachine *pThis );

    nsresult PR_COM_METHOD (*GetHWVirtExProperty)(
        IMachine *pThis,
        PRUint32 property,
        PRBool * value
    );

    nsresult PR_COM_METHOD (*SetHWVirtExProperty)(
        IMachine *pThis,
        PRUint32 property,
        PRBool value
    );

    nsresult PR_COM_METHOD (*SaveSettings)(IMachine *pThis );

    nsresult PR_COM_METHOD (*DiscardSettings)(IMachine *pThis );

    nsresult PR_COM_METHOD (*Unregister)(
        IMachine *pThis,
        PRUint32 cleanupMode,
        PRUint32 *aMediaSize,
        IMedium *** aMedia
    );

    nsresult PR_COM_METHOD (*Delete)(
        IMachine *pThis,
        PRUint32 aMediaSize,
        IMedium ** aMedia,
        IProgress * * aProgress
    );

    nsresult PR_COM_METHOD (*Export)(
        IMachine *pThis,
        IAppliance * aAppliance,
        PRUnichar * location,
        IVirtualSystemDescription * * aDescription
    );

    nsresult PR_COM_METHOD (*FindSnapshot)(
        IMachine *pThis,
        PRUnichar * nameOrId,
        ISnapshot * * snapshot
    );

    nsresult PR_COM_METHOD (*CreateSharedFolder)(
        IMachine *pThis,
        PRUnichar * name,
        PRUnichar * hostPath,
        PRBool writable,
        PRBool automount
    );

    nsresult PR_COM_METHOD (*RemoveSharedFolder)(
        IMachine *pThis,
        PRUnichar * name
    );

    nsresult PR_COM_METHOD (*CanShowConsoleWindow)(
        IMachine *pThis,
        PRBool * canShow
    );

    nsresult PR_COM_METHOD (*ShowConsoleWindow)(
        IMachine *pThis,
        PRInt64 * winId
    );

    nsresult PR_COM_METHOD (*GetGuestProperty)(
        IMachine *pThis,
        PRUnichar * name,
        PRUnichar * * value,
        PRInt64 * timestamp,
        PRUnichar * * flags
    );

    nsresult PR_COM_METHOD (*GetGuestPropertyValue)(
        IMachine *pThis,
        PRUnichar * property,
        PRUnichar * * value
    );

    nsresult PR_COM_METHOD (*GetGuestPropertyTimestamp)(
        IMachine *pThis,
        PRUnichar * property,
        PRInt64 * value
    );

    nsresult PR_COM_METHOD (*SetGuestProperty)(
        IMachine *pThis,
        PRUnichar * property,
        PRUnichar * value,
        PRUnichar * flags
    );

    nsresult PR_COM_METHOD (*SetGuestPropertyValue)(
        IMachine *pThis,
        PRUnichar * property,
        PRUnichar * value
    );

    nsresult PR_COM_METHOD (*EnumerateGuestProperties)(
        IMachine *pThis,
        PRUnichar * patterns,
        PRUint32 *nameSize,
        PRUnichar *** name,
        PRUint32 *valueSize,
        PRUnichar *** value,
        PRUint32 *timestampSize,
        PRInt64* timestamp,
        PRUint32 *flagsSize,
        PRUnichar *** flags
    );

    nsresult PR_COM_METHOD (*QuerySavedGuestSize)(
        IMachine *pThis,
        PRUint32 screenId,
        PRUint32 * width,
        PRUint32 * height
    );

    nsresult PR_COM_METHOD (*QuerySavedThumbnailSize)(
        IMachine *pThis,
        PRUint32 screenId,
        PRUint32 * size,
        PRUint32 * width,
        PRUint32 * height
    );

    nsresult PR_COM_METHOD (*ReadSavedThumbnailToArray)(
        IMachine *pThis,
        PRUint32 screenId,
        PRBool BGR,
        PRUint32 * width,
        PRUint32 * height,
        PRUint32 *dataSize,
        PRUint8** data
    );

    nsresult PR_COM_METHOD (*ReadSavedThumbnailPNGToArray)(
        IMachine *pThis,
        PRUint32 screenId,
        PRUint32 * width,
        PRUint32 * height,
        PRUint32 *dataSize,
        PRUint8** data
    );

    nsresult PR_COM_METHOD (*QuerySavedScreenshotPNGSize)(
        IMachine *pThis,
        PRUint32 screenId,
        PRUint32 * size,
        PRUint32 * width,
        PRUint32 * height
    );

    nsresult PR_COM_METHOD (*ReadSavedScreenshotPNGToArray)(
        IMachine *pThis,
        PRUint32 screenId,
        PRUint32 * width,
        PRUint32 * height,
        PRUint32 *dataSize,
        PRUint8** data
    );

    nsresult PR_COM_METHOD (*HotPlugCPU)(
        IMachine *pThis,
        PRUint32 cpu
    );

    nsresult PR_COM_METHOD (*HotUnplugCPU)(
        IMachine *pThis,
        PRUint32 cpu
    );

    nsresult PR_COM_METHOD (*GetCPUStatus)(
        IMachine *pThis,
        PRUint32 cpu,
        PRBool * attached
    );

    nsresult PR_COM_METHOD (*QueryLogFilename)(
        IMachine *pThis,
        PRUint32 idx,
        PRUnichar * * filename
    );

    nsresult PR_COM_METHOD (*ReadLog)(
        IMachine *pThis,
        PRUint32 idx,
        PRInt64 offset,
        PRInt64 size,
        PRUint32 *dataSize,
        PRUint8** data
    );

};

struct IMachine
{
    struct IMachine_vtbl *vtbl;
};
/* End of struct IMachine Declaration */


/* Start of struct IVRDEServerInfo Declaration */
#  define IVRDESERVERINFO_IID_STR "714434a1-58c3-4aab-9049-7652c5df113b"
#  define IVRDESERVERINFO_IID { \
    0x714434a1, 0x58c3, 0x4aab, \
    { 0x90, 0x49, 0x76, 0x52, 0xc5, 0xdf, 0x11, 0x3b } \
}
struct IVRDEServerInfo_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetActive)(IVRDEServerInfo *pThis, PRBool *active);

    nsresult PR_COM_METHOD (*GetPort)(IVRDEServerInfo *pThis, PRInt32 *port);

    nsresult PR_COM_METHOD (*GetNumberOfClients)(IVRDEServerInfo *pThis, PRUint32 *numberOfClients);

    nsresult PR_COM_METHOD (*GetBeginTime)(IVRDEServerInfo *pThis, PRInt64 *beginTime);

    nsresult PR_COM_METHOD (*GetEndTime)(IVRDEServerInfo *pThis, PRInt64 *endTime);

    nsresult PR_COM_METHOD (*GetBytesSent)(IVRDEServerInfo *pThis, PRInt64 *bytesSent);

    nsresult PR_COM_METHOD (*GetBytesSentTotal)(IVRDEServerInfo *pThis, PRInt64 *bytesSentTotal);

    nsresult PR_COM_METHOD (*GetBytesReceived)(IVRDEServerInfo *pThis, PRInt64 *bytesReceived);

    nsresult PR_COM_METHOD (*GetBytesReceivedTotal)(IVRDEServerInfo *pThis, PRInt64 *bytesReceivedTotal);

    nsresult PR_COM_METHOD (*GetUser)(IVRDEServerInfo *pThis, PRUnichar * *user);

    nsresult PR_COM_METHOD (*GetDomain)(IVRDEServerInfo *pThis, PRUnichar * *domain);

    nsresult PR_COM_METHOD (*GetClientName)(IVRDEServerInfo *pThis, PRUnichar * *clientName);

    nsresult PR_COM_METHOD (*GetClientIP)(IVRDEServerInfo *pThis, PRUnichar * *clientIP);

    nsresult PR_COM_METHOD (*GetClientVersion)(IVRDEServerInfo *pThis, PRUint32 *clientVersion);

    nsresult PR_COM_METHOD (*GetEncryptionStyle)(IVRDEServerInfo *pThis, PRUint32 *encryptionStyle);

};

struct IVRDEServerInfo
{
    struct IVRDEServerInfo_vtbl *vtbl;
};
/* End of struct IVRDEServerInfo Declaration */


/* Start of struct IConsole Declaration */
#  define ICONSOLE_IID_STR "515e8e8d-f932-4d8e-9f32-79a52aead882"
#  define ICONSOLE_IID { \
    0x515e8e8d, 0xf932, 0x4d8e, \
    { 0x9f, 0x32, 0x79, 0xa5, 0x2a, 0xea, 0xd8, 0x82 } \
}
struct IConsole_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetMachine)(IConsole *pThis, IMachine * *machine);

    nsresult PR_COM_METHOD (*GetState)(IConsole *pThis, PRUint32 *state);

    nsresult PR_COM_METHOD (*GetGuest)(IConsole *pThis, IGuest * *guest);

    nsresult PR_COM_METHOD (*GetKeyboard)(IConsole *pThis, IKeyboard * *keyboard);

    nsresult PR_COM_METHOD (*GetMouse)(IConsole *pThis, IMouse * *mouse);

    nsresult PR_COM_METHOD (*GetDisplay)(IConsole *pThis, IDisplay * *display);

    nsresult PR_COM_METHOD (*GetDebugger)(IConsole *pThis, IMachineDebugger * *debugger);

    nsresult PR_COM_METHOD (*GetUSBDevices)(IConsole *pThis, PRUint32 *USBDevicesSize, IUSBDevice * **USBDevices);

    nsresult PR_COM_METHOD (*GetRemoteUSBDevices)(IConsole *pThis, PRUint32 *remoteUSBDevicesSize, IHostUSBDevice * **remoteUSBDevices);

    nsresult PR_COM_METHOD (*GetSharedFolders)(IConsole *pThis, PRUint32 *sharedFoldersSize, ISharedFolder * **sharedFolders);

    nsresult PR_COM_METHOD (*GetVRDEServerInfo)(IConsole *pThis, IVRDEServerInfo * *VRDEServerInfo);

    nsresult PR_COM_METHOD (*GetEventSource)(IConsole *pThis, IEventSource * *eventSource);

    nsresult PR_COM_METHOD (*GetAttachedPciDevices)(IConsole *pThis, PRUint32 *attachedPciDevicesSize, IPciDeviceAttachment * **attachedPciDevices);

    nsresult PR_COM_METHOD (*PowerUp)(
        IConsole *pThis,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*PowerUpPaused)(
        IConsole *pThis,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*PowerDown)(
        IConsole *pThis,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*Reset)(IConsole *pThis );

    nsresult PR_COM_METHOD (*Pause)(IConsole *pThis );

    nsresult PR_COM_METHOD (*Resume)(IConsole *pThis );

    nsresult PR_COM_METHOD (*PowerButton)(IConsole *pThis );

    nsresult PR_COM_METHOD (*SleepButton)(IConsole *pThis );

    nsresult PR_COM_METHOD (*GetPowerButtonHandled)(
        IConsole *pThis,
        PRBool * handled
    );

    nsresult PR_COM_METHOD (*GetGuestEnteredACPIMode)(
        IConsole *pThis,
        PRBool * entered
    );

    nsresult PR_COM_METHOD (*SaveState)(
        IConsole *pThis,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*AdoptSavedState)(
        IConsole *pThis,
        PRUnichar * savedStateFile
    );

    nsresult PR_COM_METHOD (*DiscardSavedState)(
        IConsole *pThis,
        PRBool fRemoveFile
    );

    nsresult PR_COM_METHOD (*GetDeviceActivity)(
        IConsole *pThis,
        PRUint32 type,
        PRUint32 * activity
    );

    nsresult PR_COM_METHOD (*AttachUSBDevice)(
        IConsole *pThis,
        PRUnichar * id
    );

    nsresult PR_COM_METHOD (*DetachUSBDevice)(
        IConsole *pThis,
        PRUnichar * id,
        IUSBDevice * * device
    );

    nsresult PR_COM_METHOD (*FindUSBDeviceByAddress)(
        IConsole *pThis,
        PRUnichar * name,
        IUSBDevice * * device
    );

    nsresult PR_COM_METHOD (*FindUSBDeviceById)(
        IConsole *pThis,
        PRUnichar * id,
        IUSBDevice * * device
    );

    nsresult PR_COM_METHOD (*CreateSharedFolder)(
        IConsole *pThis,
        PRUnichar * name,
        PRUnichar * hostPath,
        PRBool writable,
        PRBool automount
    );

    nsresult PR_COM_METHOD (*RemoveSharedFolder)(
        IConsole *pThis,
        PRUnichar * name
    );

    nsresult PR_COM_METHOD (*TakeSnapshot)(
        IConsole *pThis,
        PRUnichar * name,
        PRUnichar * description,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*DeleteSnapshot)(
        IConsole *pThis,
        PRUnichar * id,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*RestoreSnapshot)(
        IConsole *pThis,
        ISnapshot * snapshot,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*Teleport)(
        IConsole *pThis,
        PRUnichar * hostname,
        PRUint32 tcpport,
        PRUnichar * password,
        PRUint32 maxDowntime,
        IProgress * * progress
    );

};

struct IConsole
{
    struct IConsole_vtbl *vtbl;
};
/* End of struct IConsole Declaration */


/* Start of struct IHostNetworkInterface Declaration */
#  define IHOSTNETWORKINTERFACE_IID_STR "ce6fae58-7642-4102-b5db-c9005c2320a8"
#  define IHOSTNETWORKINTERFACE_IID { \
    0xce6fae58, 0x7642, 0x4102, \
    { 0xb5, 0xdb, 0xc9, 0x00, 0x5c, 0x23, 0x20, 0xa8 } \
}
struct IHostNetworkInterface_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetName)(IHostNetworkInterface *pThis, PRUnichar * *name);

    nsresult PR_COM_METHOD (*GetId)(IHostNetworkInterface *pThis, PRUnichar * *id);

    nsresult PR_COM_METHOD (*GetNetworkName)(IHostNetworkInterface *pThis, PRUnichar * *networkName);

    nsresult PR_COM_METHOD (*GetDhcpEnabled)(IHostNetworkInterface *pThis, PRBool *dhcpEnabled);

    nsresult PR_COM_METHOD (*GetIPAddress)(IHostNetworkInterface *pThis, PRUnichar * *IPAddress);

    nsresult PR_COM_METHOD (*GetNetworkMask)(IHostNetworkInterface *pThis, PRUnichar * *networkMask);

    nsresult PR_COM_METHOD (*GetIPV6Supported)(IHostNetworkInterface *pThis, PRBool *IPV6Supported);

    nsresult PR_COM_METHOD (*GetIPV6Address)(IHostNetworkInterface *pThis, PRUnichar * *IPV6Address);

    nsresult PR_COM_METHOD (*GetIPV6NetworkMaskPrefixLength)(IHostNetworkInterface *pThis, PRUint32 *IPV6NetworkMaskPrefixLength);

    nsresult PR_COM_METHOD (*GetHardwareAddress)(IHostNetworkInterface *pThis, PRUnichar * *hardwareAddress);

    nsresult PR_COM_METHOD (*GetMediumType)(IHostNetworkInterface *pThis, PRUint32 *mediumType);

    nsresult PR_COM_METHOD (*GetStatus)(IHostNetworkInterface *pThis, PRUint32 *status);

    nsresult PR_COM_METHOD (*GetInterfaceType)(IHostNetworkInterface *pThis, PRUint32 *interfaceType);

    nsresult PR_COM_METHOD (*EnableStaticIpConfig)(
        IHostNetworkInterface *pThis,
        PRUnichar * IPAddress,
        PRUnichar * networkMask
    );

    nsresult PR_COM_METHOD (*EnableStaticIpConfigV6)(
        IHostNetworkInterface *pThis,
        PRUnichar * IPV6Address,
        PRUint32 IPV6NetworkMaskPrefixLength
    );

    nsresult PR_COM_METHOD (*EnableDynamicIpConfig)(IHostNetworkInterface *pThis );

    nsresult PR_COM_METHOD (*DhcpRediscover)(IHostNetworkInterface *pThis );

};

struct IHostNetworkInterface
{
    struct IHostNetworkInterface_vtbl *vtbl;
};
/* End of struct IHostNetworkInterface Declaration */


/* Start of struct IHost Declaration */
#  define IHOST_IID_STR "35b004f4-7806-4009-bfa8-d1308adba7e5"
#  define IHOST_IID { \
    0x35b004f4, 0x7806, 0x4009, \
    { 0xbf, 0xa8, 0xd1, 0x30, 0x8a, 0xdb, 0xa7, 0xe5 } \
}
struct IHost_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetDVDDrives)(IHost *pThis, PRUint32 *DVDDrivesSize, IMedium * **DVDDrives);

    nsresult PR_COM_METHOD (*GetFloppyDrives)(IHost *pThis, PRUint32 *floppyDrivesSize, IMedium * **floppyDrives);

    nsresult PR_COM_METHOD (*GetUSBDevices)(IHost *pThis, PRUint32 *USBDevicesSize, IHostUSBDevice * **USBDevices);

    nsresult PR_COM_METHOD (*GetUSBDeviceFilters)(IHost *pThis, PRUint32 *USBDeviceFiltersSize, IHostUSBDeviceFilter * **USBDeviceFilters);

    nsresult PR_COM_METHOD (*GetNetworkInterfaces)(IHost *pThis, PRUint32 *networkInterfacesSize, IHostNetworkInterface * **networkInterfaces);

    nsresult PR_COM_METHOD (*GetProcessorCount)(IHost *pThis, PRUint32 *processorCount);

    nsresult PR_COM_METHOD (*GetProcessorOnlineCount)(IHost *pThis, PRUint32 *processorOnlineCount);

    nsresult PR_COM_METHOD (*GetProcessorCoreCount)(IHost *pThis, PRUint32 *processorCoreCount);

    nsresult PR_COM_METHOD (*GetMemorySize)(IHost *pThis, PRUint32 *memorySize);

    nsresult PR_COM_METHOD (*GetMemoryAvailable)(IHost *pThis, PRUint32 *memoryAvailable);

    nsresult PR_COM_METHOD (*GetOperatingSystem)(IHost *pThis, PRUnichar * *operatingSystem);

    nsresult PR_COM_METHOD (*GetOSVersion)(IHost *pThis, PRUnichar * *OSVersion);

    nsresult PR_COM_METHOD (*GetUTCTime)(IHost *pThis, PRInt64 *UTCTime);

    nsresult PR_COM_METHOD (*GetAcceleration3DAvailable)(IHost *pThis, PRBool *Acceleration3DAvailable);

    nsresult PR_COM_METHOD (*GetProcessorSpeed)(
        IHost *pThis,
        PRUint32 cpuId,
        PRUint32 * speed
    );

    nsresult PR_COM_METHOD (*GetProcessorFeature)(
        IHost *pThis,
        PRUint32 feature,
        PRBool * supported
    );

    nsresult PR_COM_METHOD (*GetProcessorDescription)(
        IHost *pThis,
        PRUint32 cpuId,
        PRUnichar * * description
    );

    nsresult PR_COM_METHOD (*GetProcessorCPUIDLeaf)(
        IHost *pThis,
        PRUint32 cpuId,
        PRUint32 leaf,
        PRUint32 subLeaf,
        PRUint32 * valEax,
        PRUint32 * valEbx,
        PRUint32 * valEcx,
        PRUint32 * valEdx
    );

    nsresult PR_COM_METHOD (*CreateHostOnlyNetworkInterface)(
        IHost *pThis,
        IHostNetworkInterface * * hostInterface,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*RemoveHostOnlyNetworkInterface)(
        IHost *pThis,
        PRUnichar * id,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*CreateUSBDeviceFilter)(
        IHost *pThis,
        PRUnichar * name,
        IHostUSBDeviceFilter * * filter
    );

    nsresult PR_COM_METHOD (*InsertUSBDeviceFilter)(
        IHost *pThis,
        PRUint32 position,
        IHostUSBDeviceFilter * filter
    );

    nsresult PR_COM_METHOD (*RemoveUSBDeviceFilter)(
        IHost *pThis,
        PRUint32 position
    );

    nsresult PR_COM_METHOD (*FindHostDVDDrive)(
        IHost *pThis,
        PRUnichar * name,
        IMedium * * drive
    );

    nsresult PR_COM_METHOD (*FindHostFloppyDrive)(
        IHost *pThis,
        PRUnichar * name,
        IMedium * * drive
    );

    nsresult PR_COM_METHOD (*FindHostNetworkInterfaceByName)(
        IHost *pThis,
        PRUnichar * name,
        IHostNetworkInterface * * networkInterface
    );

    nsresult PR_COM_METHOD (*FindHostNetworkInterfaceById)(
        IHost *pThis,
        PRUnichar * id,
        IHostNetworkInterface * * networkInterface
    );

    nsresult PR_COM_METHOD (*FindHostNetworkInterfacesOfType)(
        IHost *pThis,
        PRUint32 type,
        PRUint32 *networkInterfacesSize,
        IHostNetworkInterface *** networkInterfaces
    );

    nsresult PR_COM_METHOD (*FindUSBDeviceById)(
        IHost *pThis,
        PRUnichar * id,
        IHostUSBDevice * * device
    );

    nsresult PR_COM_METHOD (*FindUSBDeviceByAddress)(
        IHost *pThis,
        PRUnichar * name,
        IHostUSBDevice * * device
    );

};

struct IHost
{
    struct IHost_vtbl *vtbl;
};
/* End of struct IHost Declaration */


/* Start of struct ISystemProperties Declaration */
#  define ISYSTEMPROPERTIES_IID_STR "51c81048-b261-4fa2-a44e-fd756f0db589"
#  define ISYSTEMPROPERTIES_IID { \
    0x51c81048, 0xb261, 0x4fa2, \
    { 0xa4, 0x4e, 0xfd, 0x75, 0x6f, 0x0d, 0xb5, 0x89 } \
}
struct ISystemProperties_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetMinGuestRAM)(ISystemProperties *pThis, PRUint32 *minGuestRAM);

    nsresult PR_COM_METHOD (*GetMaxGuestRAM)(ISystemProperties *pThis, PRUint32 *maxGuestRAM);

    nsresult PR_COM_METHOD (*GetMinGuestVRAM)(ISystemProperties *pThis, PRUint32 *minGuestVRAM);

    nsresult PR_COM_METHOD (*GetMaxGuestVRAM)(ISystemProperties *pThis, PRUint32 *maxGuestVRAM);

    nsresult PR_COM_METHOD (*GetMinGuestCPUCount)(ISystemProperties *pThis, PRUint32 *minGuestCPUCount);

    nsresult PR_COM_METHOD (*GetMaxGuestCPUCount)(ISystemProperties *pThis, PRUint32 *maxGuestCPUCount);

    nsresult PR_COM_METHOD (*GetMaxGuestMonitors)(ISystemProperties *pThis, PRUint32 *maxGuestMonitors);

    nsresult PR_COM_METHOD (*GetInfoVDSize)(ISystemProperties *pThis, PRInt64 *infoVDSize);

    nsresult PR_COM_METHOD (*GetNetworkAdapterCount)(ISystemProperties *pThis, PRUint32 *networkAdapterCount);

    nsresult PR_COM_METHOD (*GetSerialPortCount)(ISystemProperties *pThis, PRUint32 *serialPortCount);

    nsresult PR_COM_METHOD (*GetParallelPortCount)(ISystemProperties *pThis, PRUint32 *parallelPortCount);

    nsresult PR_COM_METHOD (*GetMaxBootPosition)(ISystemProperties *pThis, PRUint32 *maxBootPosition);

    nsresult PR_COM_METHOD (*GetDefaultMachineFolder)(ISystemProperties *pThis, PRUnichar * *defaultMachineFolder);
    nsresult PR_COM_METHOD (*SetDefaultMachineFolder)(ISystemProperties *pThis, PRUnichar * defaultMachineFolder);

    nsresult PR_COM_METHOD (*GetMediumFormats)(ISystemProperties *pThis, PRUint32 *mediumFormatsSize, IMediumFormat * **mediumFormats);

    nsresult PR_COM_METHOD (*GetDefaultHardDiskFormat)(ISystemProperties *pThis, PRUnichar * *defaultHardDiskFormat);
    nsresult PR_COM_METHOD (*SetDefaultHardDiskFormat)(ISystemProperties *pThis, PRUnichar * defaultHardDiskFormat);

    nsresult PR_COM_METHOD (*GetFreeDiskSpaceWarning)(ISystemProperties *pThis, PRInt64 *freeDiskSpaceWarning);
    nsresult PR_COM_METHOD (*SetFreeDiskSpaceWarning)(ISystemProperties *pThis, PRInt64 freeDiskSpaceWarning);

    nsresult PR_COM_METHOD (*GetFreeDiskSpacePercentWarning)(ISystemProperties *pThis, PRUint32 *freeDiskSpacePercentWarning);
    nsresult PR_COM_METHOD (*SetFreeDiskSpacePercentWarning)(ISystemProperties *pThis, PRUint32 freeDiskSpacePercentWarning);

    nsresult PR_COM_METHOD (*GetFreeDiskSpaceError)(ISystemProperties *pThis, PRInt64 *freeDiskSpaceError);
    nsresult PR_COM_METHOD (*SetFreeDiskSpaceError)(ISystemProperties *pThis, PRInt64 freeDiskSpaceError);

    nsresult PR_COM_METHOD (*GetFreeDiskSpacePercentError)(ISystemProperties *pThis, PRUint32 *freeDiskSpacePercentError);
    nsresult PR_COM_METHOD (*SetFreeDiskSpacePercentError)(ISystemProperties *pThis, PRUint32 freeDiskSpacePercentError);

    nsresult PR_COM_METHOD (*GetVRDEAuthLibrary)(ISystemProperties *pThis, PRUnichar * *VRDEAuthLibrary);
    nsresult PR_COM_METHOD (*SetVRDEAuthLibrary)(ISystemProperties *pThis, PRUnichar * VRDEAuthLibrary);

    nsresult PR_COM_METHOD (*GetWebServiceAuthLibrary)(ISystemProperties *pThis, PRUnichar * *webServiceAuthLibrary);
    nsresult PR_COM_METHOD (*SetWebServiceAuthLibrary)(ISystemProperties *pThis, PRUnichar * webServiceAuthLibrary);

    nsresult PR_COM_METHOD (*GetDefaultVRDEExtPack)(ISystemProperties *pThis, PRUnichar * *defaultVRDEExtPack);
    nsresult PR_COM_METHOD (*SetDefaultVRDEExtPack)(ISystemProperties *pThis, PRUnichar * defaultVRDEExtPack);

    nsresult PR_COM_METHOD (*GetLogHistoryCount)(ISystemProperties *pThis, PRUint32 *LogHistoryCount);
    nsresult PR_COM_METHOD (*SetLogHistoryCount)(ISystemProperties *pThis, PRUint32 LogHistoryCount);

    nsresult PR_COM_METHOD (*GetDefaultAudioDriver)(ISystemProperties *pThis, PRUint32 *defaultAudioDriver);

    nsresult PR_COM_METHOD (*GetMaxDevicesPerPortForStorageBus)(
        ISystemProperties *pThis,
        PRUint32 bus,
        PRUint32 * maxDevicesPerPort
    );

    nsresult PR_COM_METHOD (*GetMinPortCountForStorageBus)(
        ISystemProperties *pThis,
        PRUint32 bus,
        PRUint32 * minPortCount
    );

    nsresult PR_COM_METHOD (*GetMaxPortCountForStorageBus)(
        ISystemProperties *pThis,
        PRUint32 bus,
        PRUint32 * maxPortCount
    );

    nsresult PR_COM_METHOD (*GetMaxInstancesOfStorageBus)(
        ISystemProperties *pThis,
        PRUint32 chipset,
        PRUint32 bus,
        PRUint32 * maxInstances
    );

    nsresult PR_COM_METHOD (*GetDeviceTypesForStorageBus)(
        ISystemProperties *pThis,
        PRUint32 bus,
        PRUint32 *deviceTypesSize,
        PRUint32** deviceTypes
    );

    nsresult PR_COM_METHOD (*GetDefaultIoCacheSettingForStorageController)(
        ISystemProperties *pThis,
        PRUint32 controllerType,
        PRBool * enabled
    );

};

struct ISystemProperties
{
    struct ISystemProperties_vtbl *vtbl;
};
/* End of struct ISystemProperties Declaration */


/* Start of struct IGuestOSType Declaration */
#  define IGUESTOSTYPE_IID_STR "432c1546-1354-4abf-bf08-878a32a373f5"
#  define IGUESTOSTYPE_IID { \
    0x432c1546, 0x1354, 0x4abf, \
    { 0xbf, 0x08, 0x87, 0x8a, 0x32, 0xa3, 0x73, 0xf5 } \
}
struct IGuestOSType_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetFamilyId)(IGuestOSType *pThis, PRUnichar * *familyId);

    nsresult PR_COM_METHOD (*GetFamilyDescription)(IGuestOSType *pThis, PRUnichar * *familyDescription);

    nsresult PR_COM_METHOD (*GetId)(IGuestOSType *pThis, PRUnichar * *id);

    nsresult PR_COM_METHOD (*GetDescription)(IGuestOSType *pThis, PRUnichar * *description);

    nsresult PR_COM_METHOD (*GetIs64Bit)(IGuestOSType *pThis, PRBool *is64Bit);

    nsresult PR_COM_METHOD (*GetRecommendedIOAPIC)(IGuestOSType *pThis, PRBool *recommendedIOAPIC);

    nsresult PR_COM_METHOD (*GetRecommendedVirtEx)(IGuestOSType *pThis, PRBool *recommendedVirtEx);

    nsresult PR_COM_METHOD (*GetRecommendedRAM)(IGuestOSType *pThis, PRUint32 *recommendedRAM);

    nsresult PR_COM_METHOD (*GetRecommendedVRAM)(IGuestOSType *pThis, PRUint32 *recommendedVRAM);

    nsresult PR_COM_METHOD (*GetRecommendedHDD)(IGuestOSType *pThis, PRInt64 *recommendedHDD);

    nsresult PR_COM_METHOD (*GetAdapterType)(IGuestOSType *pThis, PRUint32 *adapterType);

    nsresult PR_COM_METHOD (*GetRecommendedPae)(IGuestOSType *pThis, PRBool *recommendedPae);

    nsresult PR_COM_METHOD (*GetRecommendedDvdStorageController)(IGuestOSType *pThis, PRUint32 *recommendedDvdStorageController);

    nsresult PR_COM_METHOD (*GetRecommendedDvdStorageBus)(IGuestOSType *pThis, PRUint32 *recommendedDvdStorageBus);

    nsresult PR_COM_METHOD (*GetRecommendedHdStorageController)(IGuestOSType *pThis, PRUint32 *recommendedHdStorageController);

    nsresult PR_COM_METHOD (*GetRecommendedHdStorageBus)(IGuestOSType *pThis, PRUint32 *recommendedHdStorageBus);

    nsresult PR_COM_METHOD (*GetRecommendedFirmware)(IGuestOSType *pThis, PRUint32 *recommendedFirmware);

    nsresult PR_COM_METHOD (*GetRecommendedUsbHid)(IGuestOSType *pThis, PRBool *recommendedUsbHid);

    nsresult PR_COM_METHOD (*GetRecommendedHpet)(IGuestOSType *pThis, PRBool *recommendedHpet);

    nsresult PR_COM_METHOD (*GetRecommendedUsbTablet)(IGuestOSType *pThis, PRBool *recommendedUsbTablet);

    nsresult PR_COM_METHOD (*GetRecommendedRtcUseUtc)(IGuestOSType *pThis, PRBool *recommendedRtcUseUtc);

    nsresult PR_COM_METHOD (*GetRecommendedChipset)(IGuestOSType *pThis, PRUint32 *recommendedChipset);

    nsresult PR_COM_METHOD (*GetRecommendedAudioController)(IGuestOSType *pThis, PRUint32 *recommendedAudioController);

};

struct IGuestOSType
{
    struct IGuestOSType_vtbl *vtbl;
};
/* End of struct IGuestOSType Declaration */


/* Start of struct IGuest Declaration */
#  define IGUEST_IID_STR "7ce7e4d8-cdaa-4d83-a0f4-510c8ee70aea"
#  define IGUEST_IID { \
    0x7ce7e4d8, 0xcdaa, 0x4d83, \
    { 0xa0, 0xf4, 0x51, 0x0c, 0x8e, 0xe7, 0x0a, 0xea } \
}
struct IGuest_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetOSTypeId)(IGuest *pThis, PRUnichar * *OSTypeId);

    nsresult PR_COM_METHOD (*GetAdditionsRunLevel)(IGuest *pThis, PRUint32 *additionsRunLevel);

    nsresult PR_COM_METHOD (*GetAdditionsVersion)(IGuest *pThis, PRUnichar * *additionsVersion);

    nsresult PR_COM_METHOD (*GetSupportsSeamless)(IGuest *pThis, PRBool *supportsSeamless);

    nsresult PR_COM_METHOD (*GetSupportsGraphics)(IGuest *pThis, PRBool *supportsGraphics);

    nsresult PR_COM_METHOD (*GetMemoryBalloonSize)(IGuest *pThis, PRUint32 *memoryBalloonSize);
    nsresult PR_COM_METHOD (*SetMemoryBalloonSize)(IGuest *pThis, PRUint32 memoryBalloonSize);

    nsresult PR_COM_METHOD (*GetStatisticsUpdateInterval)(IGuest *pThis, PRUint32 *statisticsUpdateInterval);
    nsresult PR_COM_METHOD (*SetStatisticsUpdateInterval)(IGuest *pThis, PRUint32 statisticsUpdateInterval);

    nsresult PR_COM_METHOD (*InternalGetStatistics)(
        IGuest *pThis,
        PRUint32 * cpuUser,
        PRUint32 * cpuKernel,
        PRUint32 * cpuIdle,
        PRUint32 * memTotal,
        PRUint32 * memFree,
        PRUint32 * memBalloon,
        PRUint32 * memShared,
        PRUint32 * memCache,
        PRUint32 * pagedTotal,
        PRUint32 * memAllocTotal,
        PRUint32 * memFreeTotal,
        PRUint32 * memBalloonTotal,
        PRUint32 * memSharedTotal
    );

    nsresult PR_COM_METHOD (*GetAdditionsStatus)(
        IGuest *pThis,
        PRUint32 level,
        PRBool * active
    );

    nsresult PR_COM_METHOD (*SetCredentials)(
        IGuest *pThis,
        PRUnichar * userName,
        PRUnichar * password,
        PRUnichar * domain,
        PRBool allowInteractiveLogon
    );

    nsresult PR_COM_METHOD (*ExecuteProcess)(
        IGuest *pThis,
        PRUnichar * execName,
        PRUint32 flags,
        PRUint32 argumentsSize,
        PRUnichar ** arguments,
        PRUint32 environmentSize,
        PRUnichar ** environment,
        PRUnichar * userName,
        PRUnichar * password,
        PRUint32 timeoutMS,
        PRUint32 * pid,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*GetProcessOutput)(
        IGuest *pThis,
        PRUint32 pid,
        PRUint32 flags,
        PRUint32 timeoutMS,
        PRInt64 size,
        PRUint32 *dataSize,
        PRUint8** data
    );

    nsresult PR_COM_METHOD (*GetProcessStatus)(
        IGuest *pThis,
        PRUint32 pid,
        PRUint32 * exitcode,
        PRUint32 * flags,
        PRUint32 * reason
    );

    nsresult PR_COM_METHOD (*CopyToGuest)(
        IGuest *pThis,
        PRUnichar * source,
        PRUnichar * dest,
        PRUnichar * userName,
        PRUnichar * password,
        PRUint32 flags,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*CreateDirectory)(
        IGuest *pThis,
        PRUnichar * directory,
        PRUnichar * userName,
        PRUnichar * password,
        PRUint32 mode,
        PRUint32 flags,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*SetProcessInput)(
        IGuest *pThis,
        PRUint32 pid,
        PRUint32 flags,
        PRUint32 timeoutMS,
        PRUint32 dataSize,
        PRUint8* data,
        PRUint32 * written
    );

    nsresult PR_COM_METHOD (*UpdateGuestAdditions)(
        IGuest *pThis,
        PRUnichar * source,
        PRUint32 flags,
        IProgress * * progress
    );

};

struct IGuest
{
    struct IGuest_vtbl *vtbl;
};
/* End of struct IGuest Declaration */


/* Start of struct IProgress Declaration */
#  define IPROGRESS_IID_STR "A163C98F-8635-4AA8-B770-A9941737F3EF"
#  define IPROGRESS_IID { \
    0xA163C98F, 0x8635, 0x4AA8, \
    { 0xB7, 0x70, 0xA9, 0x94, 0x17, 0x37, 0xF3, 0xEF } \
}
struct IProgress_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetId)(IProgress *pThis, PRUnichar * *id);

    nsresult PR_COM_METHOD (*GetDescription)(IProgress *pThis, PRUnichar * *description);

    nsresult PR_COM_METHOD (*GetInitiator)(IProgress *pThis, nsISupports * *initiator);

    nsresult PR_COM_METHOD (*GetCancelable)(IProgress *pThis, PRBool *cancelable);

    nsresult PR_COM_METHOD (*GetPercent)(IProgress *pThis, PRUint32 *percent);

    nsresult PR_COM_METHOD (*GetTimeRemaining)(IProgress *pThis, PRInt32 *timeRemaining);

    nsresult PR_COM_METHOD (*GetCompleted)(IProgress *pThis, PRBool *completed);

    nsresult PR_COM_METHOD (*GetCanceled)(IProgress *pThis, PRBool *canceled);

    nsresult PR_COM_METHOD (*GetResultCode)(IProgress *pThis, PRInt32 *resultCode);

    nsresult PR_COM_METHOD (*GetErrorInfo)(IProgress *pThis, IVirtualBoxErrorInfo * *errorInfo);

    nsresult PR_COM_METHOD (*GetOperationCount)(IProgress *pThis, PRUint32 *operationCount);

    nsresult PR_COM_METHOD (*GetOperation)(IProgress *pThis, PRUint32 *operation);

    nsresult PR_COM_METHOD (*GetOperationDescription)(IProgress *pThis, PRUnichar * *operationDescription);

    nsresult PR_COM_METHOD (*GetOperationPercent)(IProgress *pThis, PRUint32 *operationPercent);

    nsresult PR_COM_METHOD (*GetOperationWeight)(IProgress *pThis, PRUint32 *operationWeight);

    nsresult PR_COM_METHOD (*GetTimeout)(IProgress *pThis, PRUint32 *timeout);
    nsresult PR_COM_METHOD (*SetTimeout)(IProgress *pThis, PRUint32 timeout);

    nsresult PR_COM_METHOD (*SetCurrentOperationProgress)(
        IProgress *pThis,
        PRUint32 percent
    );

    nsresult PR_COM_METHOD (*SetNextOperation)(
        IProgress *pThis,
        PRUnichar * nextOperationDescription,
        PRUint32 nextOperationsWeight
    );

    nsresult PR_COM_METHOD (*WaitForCompletion)(
        IProgress *pThis,
        PRInt32 timeout
    );

    nsresult PR_COM_METHOD (*WaitForOperationCompletion)(
        IProgress *pThis,
        PRUint32 operation,
        PRInt32 timeout
    );

    nsresult PR_COM_METHOD (*Cancel)(IProgress *pThis );

};

struct IProgress
{
    struct IProgress_vtbl *vtbl;
};
/* End of struct IProgress Declaration */


/* Start of struct ISnapshot Declaration */
#  define ISNAPSHOT_IID_STR "1a2d0551-58a4-4107-857e-ef414fc42ffc"
#  define ISNAPSHOT_IID { \
    0x1a2d0551, 0x58a4, 0x4107, \
    { 0x85, 0x7e, 0xef, 0x41, 0x4f, 0xc4, 0x2f, 0xfc } \
}
struct ISnapshot_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetId)(ISnapshot *pThis, PRUnichar * *id);

    nsresult PR_COM_METHOD (*GetName)(ISnapshot *pThis, PRUnichar * *name);
    nsresult PR_COM_METHOD (*SetName)(ISnapshot *pThis, PRUnichar * name);

    nsresult PR_COM_METHOD (*GetDescription)(ISnapshot *pThis, PRUnichar * *description);
    nsresult PR_COM_METHOD (*SetDescription)(ISnapshot *pThis, PRUnichar * description);

    nsresult PR_COM_METHOD (*GetTimeStamp)(ISnapshot *pThis, PRInt64 *timeStamp);

    nsresult PR_COM_METHOD (*GetOnline)(ISnapshot *pThis, PRBool *online);

    nsresult PR_COM_METHOD (*GetMachine)(ISnapshot *pThis, IMachine * *machine);

    nsresult PR_COM_METHOD (*GetParent)(ISnapshot *pThis, ISnapshot * *parent);

    nsresult PR_COM_METHOD (*GetChildren)(ISnapshot *pThis, PRUint32 *childrenSize, ISnapshot * **children);

};

struct ISnapshot
{
    struct ISnapshot_vtbl *vtbl;
};
/* End of struct ISnapshot Declaration */


/* Start of struct IMediumAttachment Declaration */
#  define IMEDIUMATTACHMENT_IID_STR "aa4b4840-934f-454d-9a28-23e8f4235edf"
#  define IMEDIUMATTACHMENT_IID { \
    0xaa4b4840, 0x934f, 0x454d, \
    { 0x9a, 0x28, 0x23, 0xe8, 0xf4, 0x23, 0x5e, 0xdf } \
}
struct IMediumAttachment_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetMedium)(IMediumAttachment *pThis, IMedium * *medium);

    nsresult PR_COM_METHOD (*GetController)(IMediumAttachment *pThis, PRUnichar * *controller);

    nsresult PR_COM_METHOD (*GetPort)(IMediumAttachment *pThis, PRInt32 *port);

    nsresult PR_COM_METHOD (*GetDevice)(IMediumAttachment *pThis, PRInt32 *device);

    nsresult PR_COM_METHOD (*GetType)(IMediumAttachment *pThis, PRUint32 *type);

    nsresult PR_COM_METHOD (*GetPassthrough)(IMediumAttachment *pThis, PRBool *passthrough);

    nsresult PR_COM_METHOD (*GetBandwidthGroup)(IMediumAttachment *pThis, IBandwidthGroup * *bandwidthGroup);

};

struct IMediumAttachment
{
    struct IMediumAttachment_vtbl *vtbl;
};
/* End of struct IMediumAttachment Declaration */


/* Start of struct IMedium Declaration */
#  define IMEDIUM_IID_STR "9edda847-1279-4b0a-9af7-9d66251ccc18"
#  define IMEDIUM_IID { \
    0x9edda847, 0x1279, 0x4b0a, \
    { 0x9a, 0xf7, 0x9d, 0x66, 0x25, 0x1c, 0xcc, 0x18 } \
}
struct IMedium_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetId)(IMedium *pThis, PRUnichar * *id);

    nsresult PR_COM_METHOD (*GetDescription)(IMedium *pThis, PRUnichar * *description);
    nsresult PR_COM_METHOD (*SetDescription)(IMedium *pThis, PRUnichar * description);

    nsresult PR_COM_METHOD (*GetState)(IMedium *pThis, PRUint32 *state);

    nsresult PR_COM_METHOD (*GetVariant)(IMedium *pThis, PRUint32 *variant);

    nsresult PR_COM_METHOD (*GetLocation)(IMedium *pThis, PRUnichar * *location);
    nsresult PR_COM_METHOD (*SetLocation)(IMedium *pThis, PRUnichar * location);

    nsresult PR_COM_METHOD (*GetName)(IMedium *pThis, PRUnichar * *name);

    nsresult PR_COM_METHOD (*GetDeviceType)(IMedium *pThis, PRUint32 *deviceType);

    nsresult PR_COM_METHOD (*GetHostDrive)(IMedium *pThis, PRBool *hostDrive);

    nsresult PR_COM_METHOD (*GetSize)(IMedium *pThis, PRInt64 *size);

    nsresult PR_COM_METHOD (*GetFormat)(IMedium *pThis, PRUnichar * *format);

    nsresult PR_COM_METHOD (*GetMediumFormat)(IMedium *pThis, IMediumFormat * *mediumFormat);

    nsresult PR_COM_METHOD (*GetType)(IMedium *pThis, PRUint32 *type);
    nsresult PR_COM_METHOD (*SetType)(IMedium *pThis, PRUint32 type);

    nsresult PR_COM_METHOD (*GetParent)(IMedium *pThis, IMedium * *parent);

    nsresult PR_COM_METHOD (*GetChildren)(IMedium *pThis, PRUint32 *childrenSize, IMedium * **children);

    nsresult PR_COM_METHOD (*GetBase)(IMedium *pThis, IMedium * *base);

    nsresult PR_COM_METHOD (*GetReadOnly)(IMedium *pThis, PRBool *readOnly);

    nsresult PR_COM_METHOD (*GetLogicalSize)(IMedium *pThis, PRInt64 *logicalSize);

    nsresult PR_COM_METHOD (*GetAutoReset)(IMedium *pThis, PRBool *autoReset);
    nsresult PR_COM_METHOD (*SetAutoReset)(IMedium *pThis, PRBool autoReset);

    nsresult PR_COM_METHOD (*GetLastAccessError)(IMedium *pThis, PRUnichar * *lastAccessError);

    nsresult PR_COM_METHOD (*GetMachineIds)(IMedium *pThis, PRUint32 *machineIdsSize, PRUnichar * **machineIds);

    nsresult PR_COM_METHOD (*SetIDs)(
        IMedium *pThis,
        PRBool setImageId,
        PRUnichar * imageId,
        PRBool setParentId,
        PRUnichar * parentId
    );

    nsresult PR_COM_METHOD (*RefreshState)(
        IMedium *pThis,
        PRUint32 * state
    );

    nsresult PR_COM_METHOD (*GetSnapshotIds)(
        IMedium *pThis,
        PRUnichar * machineId,
        PRUint32 *snapshotIdsSize,
        PRUnichar *** snapshotIds
    );

    nsresult PR_COM_METHOD (*LockRead)(
        IMedium *pThis,
        PRUint32 * state
    );

    nsresult PR_COM_METHOD (*UnlockRead)(
        IMedium *pThis,
        PRUint32 * state
    );

    nsresult PR_COM_METHOD (*LockWrite)(
        IMedium *pThis,
        PRUint32 * state
    );

    nsresult PR_COM_METHOD (*UnlockWrite)(
        IMedium *pThis,
        PRUint32 * state
    );

    nsresult PR_COM_METHOD (*Close)(IMedium *pThis );

    nsresult PR_COM_METHOD (*GetProperty)(
        IMedium *pThis,
        PRUnichar * name,
        PRUnichar * * value
    );

    nsresult PR_COM_METHOD (*SetProperty)(
        IMedium *pThis,
        PRUnichar * name,
        PRUnichar * value
    );

    nsresult PR_COM_METHOD (*GetProperties)(
        IMedium *pThis,
        PRUnichar * names,
        PRUint32 *returnNamesSize,
        PRUnichar *** returnNames,
        PRUint32 *returnValuesSize,
        PRUnichar *** returnValues
    );

    nsresult PR_COM_METHOD (*SetProperties)(
        IMedium *pThis,
        PRUint32 namesSize,
        PRUnichar ** names,
        PRUint32 valuesSize,
        PRUnichar ** values
    );

    nsresult PR_COM_METHOD (*CreateBaseStorage)(
        IMedium *pThis,
        PRInt64 logicalSize,
        PRUint32 variant,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*DeleteStorage)(
        IMedium *pThis,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*CreateDiffStorage)(
        IMedium *pThis,
        IMedium * target,
        PRUint32 variant,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*MergeTo)(
        IMedium *pThis,
        IMedium * target,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*CloneTo)(
        IMedium *pThis,
        IMedium * target,
        PRUint32 variant,
        IMedium * parent,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*Compact)(
        IMedium *pThis,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*Resize)(
        IMedium *pThis,
        PRInt64 logicalSize,
        IProgress * * progress
    );

    nsresult PR_COM_METHOD (*Reset)(
        IMedium *pThis,
        IProgress * * progress
    );

};

struct IMedium
{
    struct IMedium_vtbl *vtbl;
};
/* End of struct IMedium Declaration */


/* Start of struct IMediumFormat Declaration */
#  define IMEDIUMFORMAT_IID_STR "4e9a873f-0599-434a-8345-619ef3fb3111"
#  define IMEDIUMFORMAT_IID { \
    0x4e9a873f, 0x0599, 0x434a, \
    { 0x83, 0x45, 0x61, 0x9e, 0xf3, 0xfb, 0x31, 0x11 } \
}
struct IMediumFormat_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetId)(IMediumFormat *pThis, PRUnichar * *id);

    nsresult PR_COM_METHOD (*GetName)(IMediumFormat *pThis, PRUnichar * *name);

    nsresult PR_COM_METHOD (*GetCapabilities)(IMediumFormat *pThis, PRUint32 *capabilities);

    nsresult PR_COM_METHOD (*DescribeFileExtensions)(
        IMediumFormat *pThis,
        PRUint32 *extensionsSize,
        PRUnichar *** extensions,
        PRUint32 *typeSize,
        PRUint32* type
    );

    nsresult PR_COM_METHOD (*DescribeProperties)(
        IMediumFormat *pThis,
        PRUint32 *namesSize,
        PRUnichar *** names,
        PRUint32 *descriptionSize,
        PRUnichar *** description,
        PRUint32 *typesSize,
        PRUint32* types,
        PRUint32 *flagsSize,
        PRUint32* flags,
        PRUint32 *defaultsSize,
        PRUnichar *** defaults
    );

};

struct IMediumFormat
{
    struct IMediumFormat_vtbl *vtbl;
};
/* End of struct IMediumFormat Declaration */


/* Start of struct IKeyboard Declaration */
#  define IKEYBOARD_IID_STR "f6916ec5-a881-4237-898f-7de58cf88672"
#  define IKEYBOARD_IID { \
    0xf6916ec5, 0xa881, 0x4237, \
    { 0x89, 0x8f, 0x7d, 0xe5, 0x8c, 0xf8, 0x86, 0x72 } \
}
struct IKeyboard_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetEventSource)(IKeyboard *pThis, IEventSource * *eventSource);

    nsresult PR_COM_METHOD (*PutScancode)(
        IKeyboard *pThis,
        PRInt32 scancode
    );

    nsresult PR_COM_METHOD (*PutScancodes)(
        IKeyboard *pThis,
        PRUint32 scancodesSize,
        PRInt32* scancodes,
        PRUint32 * codesStored
    );

    nsresult PR_COM_METHOD (*PutCAD)(IKeyboard *pThis );

};

struct IKeyboard
{
    struct IKeyboard_vtbl *vtbl;
};
/* End of struct IKeyboard Declaration */


/* Start of struct IMouse Declaration */
#  define IMOUSE_IID_STR "05044a52-7811-4f00-ae3a-0ab7ff707b10"
#  define IMOUSE_IID { \
    0x05044a52, 0x7811, 0x4f00, \
    { 0xae, 0x3a, 0x0a, 0xb7, 0xff, 0x70, 0x7b, 0x10 } \
}
struct IMouse_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetAbsoluteSupported)(IMouse *pThis, PRBool *absoluteSupported);

    nsresult PR_COM_METHOD (*GetRelativeSupported)(IMouse *pThis, PRBool *relativeSupported);

    nsresult PR_COM_METHOD (*GetNeedsHostCursor)(IMouse *pThis, PRBool *needsHostCursor);

    nsresult PR_COM_METHOD (*GetEventSource)(IMouse *pThis, IEventSource * *eventSource);

    nsresult PR_COM_METHOD (*PutMouseEvent)(
        IMouse *pThis,
        PRInt32 dx,
        PRInt32 dy,
        PRInt32 dz,
        PRInt32 dw,
        PRInt32 buttonState
    );

    nsresult PR_COM_METHOD (*PutMouseEventAbsolute)(
        IMouse *pThis,
        PRInt32 x,
        PRInt32 y,
        PRInt32 dz,
        PRInt32 dw,
        PRInt32 buttonState
    );

};

struct IMouse
{
    struct IMouse_vtbl *vtbl;
};
/* End of struct IMouse Declaration */


/* Start of struct IFramebuffer Declaration */
#  define IFRAMEBUFFER_IID_STR "b7ed347a-5765-40a0-ae1c-f543eb4ddeaf"
#  define IFRAMEBUFFER_IID { \
    0xb7ed347a, 0x5765, 0x40a0, \
    { 0xae, 0x1c, 0xf5, 0x43, 0xeb, 0x4d, 0xde, 0xaf } \
}
struct IFramebuffer_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetAddress)(IFramebuffer *pThis, PRUint8 * *address);

    nsresult PR_COM_METHOD (*GetWidth)(IFramebuffer *pThis, PRUint32 *width);

    nsresult PR_COM_METHOD (*GetHeight)(IFramebuffer *pThis, PRUint32 *height);

    nsresult PR_COM_METHOD (*GetBitsPerPixel)(IFramebuffer *pThis, PRUint32 *bitsPerPixel);

    nsresult PR_COM_METHOD (*GetBytesPerLine)(IFramebuffer *pThis, PRUint32 *bytesPerLine);

    nsresult PR_COM_METHOD (*GetPixelFormat)(IFramebuffer *pThis, PRUint32 *pixelFormat);

    nsresult PR_COM_METHOD (*GetUsesGuestVRAM)(IFramebuffer *pThis, PRBool *usesGuestVRAM);

    nsresult PR_COM_METHOD (*GetHeightReduction)(IFramebuffer *pThis, PRUint32 *heightReduction);

    nsresult PR_COM_METHOD (*GetOverlay)(IFramebuffer *pThis, IFramebufferOverlay * *overlay);

    nsresult PR_COM_METHOD (*GetWinId)(IFramebuffer *pThis, PRInt64 *winId);

    nsresult PR_COM_METHOD (*Lock)(IFramebuffer *pThis );

    nsresult PR_COM_METHOD (*Unlock)(IFramebuffer *pThis );

    nsresult PR_COM_METHOD (*NotifyUpdate)(
        IFramebuffer *pThis,
        PRUint32 x,
        PRUint32 y,
        PRUint32 width,
        PRUint32 height
    );

    nsresult PR_COM_METHOD (*RequestResize)(
        IFramebuffer *pThis,
        PRUint32 screenId,
        PRUint32 pixelFormat,
        PRUint8 * VRAM,
        PRUint32 bitsPerPixel,
        PRUint32 bytesPerLine,
        PRUint32 width,
        PRUint32 height,
        PRBool * finished
    );

    nsresult PR_COM_METHOD (*VideoModeSupported)(
        IFramebuffer *pThis,
        PRUint32 width,
        PRUint32 height,
        PRUint32 bpp,
        PRBool * supported
    );

    nsresult PR_COM_METHOD (*GetVisibleRegion)(
        IFramebuffer *pThis,
        PRUint8 * rectangles,
        PRUint32 count,
        PRUint32 * countCopied
    );

    nsresult PR_COM_METHOD (*SetVisibleRegion)(
        IFramebuffer *pThis,
        PRUint8 * rectangles,
        PRUint32 count
    );

    nsresult PR_COM_METHOD (*ProcessVHWACommand)(
        IFramebuffer *pThis,
        PRUint8 * command
    );

};

struct IFramebuffer
{
    struct IFramebuffer_vtbl *vtbl;
};
/* End of struct IFramebuffer Declaration */


/* Start of struct IFramebufferOverlay Declaration */
#  define IFRAMEBUFFEROVERLAY_IID_STR "0bcc1c7e-e415-47d2-bfdb-e4c705fb0f47"
#  define IFRAMEBUFFEROVERLAY_IID { \
    0x0bcc1c7e, 0xe415, 0x47d2, \
    { 0xbf, 0xdb, 0xe4, 0xc7, 0x05, 0xfb, 0x0f, 0x47 } \
}
struct IFramebufferOverlay_vtbl
{
    struct IFramebuffer_vtbl iframebuffer;

    nsresult PR_COM_METHOD (*GetX)(IFramebufferOverlay *pThis, PRUint32 *x);

    nsresult PR_COM_METHOD (*GetY)(IFramebufferOverlay *pThis, PRUint32 *y);

    nsresult PR_COM_METHOD (*GetVisible)(IFramebufferOverlay *pThis, PRBool *visible);
    nsresult PR_COM_METHOD (*SetVisible)(IFramebufferOverlay *pThis, PRBool visible);

    nsresult PR_COM_METHOD (*GetAlpha)(IFramebufferOverlay *pThis, PRUint32 *alpha);
    nsresult PR_COM_METHOD (*SetAlpha)(IFramebufferOverlay *pThis, PRUint32 alpha);

    nsresult PR_COM_METHOD (*Move)(
        IFramebufferOverlay *pThis,
        PRUint32 x,
        PRUint32 y
    );

};

struct IFramebufferOverlay
{
    struct IFramebufferOverlay_vtbl *vtbl;
};
/* End of struct IFramebufferOverlay Declaration */


/* Start of struct IDisplay Declaration */
#  define IDISPLAY_IID_STR "09EED313-CD56-4D06-BD56-FAC0F716B5DD"
#  define IDISPLAY_IID { \
    0x09EED313, 0xCD56, 0x4D06, \
    { 0xBD, 0x56, 0xFA, 0xC0, 0xF7, 0x16, 0xB5, 0xDD } \
}
struct IDisplay_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetScreenResolution)(
        IDisplay *pThis,
        PRUint32 screenId,
        PRUint32 * width,
        PRUint32 * height,
        PRUint32 * bitsPerPixel
    );

    nsresult PR_COM_METHOD (*SetFramebuffer)(
        IDisplay *pThis,
        PRUint32 screenId,
        IFramebuffer * framebuffer
    );

    nsresult PR_COM_METHOD (*GetFramebuffer)(
        IDisplay *pThis,
        PRUint32 screenId,
        IFramebuffer * * framebuffer,
        PRInt32 * xOrigin,
        PRInt32 * yOrigin
    );

    nsresult PR_COM_METHOD (*SetVideoModeHint)(
        IDisplay *pThis,
        PRUint32 width,
        PRUint32 height,
        PRUint32 bitsPerPixel,
        PRUint32 display
    );

    nsresult PR_COM_METHOD (*SetSeamlessMode)(
        IDisplay *pThis,
        PRBool enabled
    );

    nsresult PR_COM_METHOD (*TakeScreenShot)(
        IDisplay *pThis,
        PRUint32 screenId,
        PRUint8 * address,
        PRUint32 width,
        PRUint32 height
    );

    nsresult PR_COM_METHOD (*TakeScreenShotToArray)(
        IDisplay *pThis,
        PRUint32 screenId,
        PRUint32 width,
        PRUint32 height,
        PRUint32 *screenDataSize,
        PRUint8** screenData
    );

    nsresult PR_COM_METHOD (*TakeScreenShotPNGToArray)(
        IDisplay *pThis,
        PRUint32 screenId,
        PRUint32 width,
        PRUint32 height,
        PRUint32 *screenDataSize,
        PRUint8** screenData
    );

    nsresult PR_COM_METHOD (*DrawToScreen)(
        IDisplay *pThis,
        PRUint32 screenId,
        PRUint8 * address,
        PRUint32 x,
        PRUint32 y,
        PRUint32 width,
        PRUint32 height
    );

    nsresult PR_COM_METHOD (*InvalidateAndUpdate)(IDisplay *pThis );

    nsresult PR_COM_METHOD (*ResizeCompleted)(
        IDisplay *pThis,
        PRUint32 screenId
    );

    nsresult PR_COM_METHOD (*CompleteVHWACommand)(
        IDisplay *pThis,
        PRUint8 * command
    );

};

struct IDisplay
{
    struct IDisplay_vtbl *vtbl;
};
/* End of struct IDisplay Declaration */


/* Start of struct INetworkAdapter Declaration */
#  define INETWORKADAPTER_IID_STR "9bf58a46-c3f7-4f31-80fa-dde9a5dc0b7b"
#  define INETWORKADAPTER_IID { \
    0x9bf58a46, 0xc3f7, 0x4f31, \
    { 0x80, 0xfa, 0xdd, 0xe9, 0xa5, 0xdc, 0x0b, 0x7b } \
}
struct INetworkAdapter_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetAdapterType)(INetworkAdapter *pThis, PRUint32 *adapterType);
    nsresult PR_COM_METHOD (*SetAdapterType)(INetworkAdapter *pThis, PRUint32 adapterType);

    nsresult PR_COM_METHOD (*GetSlot)(INetworkAdapter *pThis, PRUint32 *slot);

    nsresult PR_COM_METHOD (*GetEnabled)(INetworkAdapter *pThis, PRBool *enabled);
    nsresult PR_COM_METHOD (*SetEnabled)(INetworkAdapter *pThis, PRBool enabled);

    nsresult PR_COM_METHOD (*GetMACAddress)(INetworkAdapter *pThis, PRUnichar * *MACAddress);
    nsresult PR_COM_METHOD (*SetMACAddress)(INetworkAdapter *pThis, PRUnichar * MACAddress);

    nsresult PR_COM_METHOD (*GetAttachmentType)(INetworkAdapter *pThis, PRUint32 *attachmentType);

    nsresult PR_COM_METHOD (*GetHostInterface)(INetworkAdapter *pThis, PRUnichar * *hostInterface);
    nsresult PR_COM_METHOD (*SetHostInterface)(INetworkAdapter *pThis, PRUnichar * hostInterface);

    nsresult PR_COM_METHOD (*GetInternalNetwork)(INetworkAdapter *pThis, PRUnichar * *internalNetwork);
    nsresult PR_COM_METHOD (*SetInternalNetwork)(INetworkAdapter *pThis, PRUnichar * internalNetwork);

    nsresult PR_COM_METHOD (*GetNATNetwork)(INetworkAdapter *pThis, PRUnichar * *NATNetwork);
    nsresult PR_COM_METHOD (*SetNATNetwork)(INetworkAdapter *pThis, PRUnichar * NATNetwork);

    nsresult PR_COM_METHOD (*GetVDENetwork)(INetworkAdapter *pThis, PRUnichar * *VDENetwork);
    nsresult PR_COM_METHOD (*SetVDENetwork)(INetworkAdapter *pThis, PRUnichar * VDENetwork);

    nsresult PR_COM_METHOD (*GetCableConnected)(INetworkAdapter *pThis, PRBool *cableConnected);
    nsresult PR_COM_METHOD (*SetCableConnected)(INetworkAdapter *pThis, PRBool cableConnected);

    nsresult PR_COM_METHOD (*GetLineSpeed)(INetworkAdapter *pThis, PRUint32 *lineSpeed);
    nsresult PR_COM_METHOD (*SetLineSpeed)(INetworkAdapter *pThis, PRUint32 lineSpeed);

    nsresult PR_COM_METHOD (*GetTraceEnabled)(INetworkAdapter *pThis, PRBool *traceEnabled);
    nsresult PR_COM_METHOD (*SetTraceEnabled)(INetworkAdapter *pThis, PRBool traceEnabled);

    nsresult PR_COM_METHOD (*GetTraceFile)(INetworkAdapter *pThis, PRUnichar * *traceFile);
    nsresult PR_COM_METHOD (*SetTraceFile)(INetworkAdapter *pThis, PRUnichar * traceFile);

    nsresult PR_COM_METHOD (*GetNatDriver)(INetworkAdapter *pThis, INATEngine * *natDriver);

    nsresult PR_COM_METHOD (*GetBootPriority)(INetworkAdapter *pThis, PRUint32 *bootPriority);
    nsresult PR_COM_METHOD (*SetBootPriority)(INetworkAdapter *pThis, PRUint32 bootPriority);

    nsresult PR_COM_METHOD (*GetBandwidthLimit)(INetworkAdapter *pThis, PRUint32 *bandwidthLimit);
    nsresult PR_COM_METHOD (*SetBandwidthLimit)(INetworkAdapter *pThis, PRUint32 bandwidthLimit);

    nsresult PR_COM_METHOD (*AttachToNAT)(INetworkAdapter *pThis );

    nsresult PR_COM_METHOD (*AttachToBridgedInterface)(INetworkAdapter *pThis );

    nsresult PR_COM_METHOD (*AttachToInternalNetwork)(INetworkAdapter *pThis );

    nsresult PR_COM_METHOD (*AttachToHostOnlyInterface)(INetworkAdapter *pThis );

    nsresult PR_COM_METHOD (*AttachToVDE)(INetworkAdapter *pThis );

    nsresult PR_COM_METHOD (*Detach)(INetworkAdapter *pThis );

};

struct INetworkAdapter
{
    struct INetworkAdapter_vtbl *vtbl;
};
/* End of struct INetworkAdapter Declaration */


/* Start of struct ISerialPort Declaration */
#  define ISERIALPORT_IID_STR "937f6970-5103-4745-b78e-d28dcf1479a8"
#  define ISERIALPORT_IID { \
    0x937f6970, 0x5103, 0x4745, \
    { 0xb7, 0x8e, 0xd2, 0x8d, 0xcf, 0x14, 0x79, 0xa8 } \
}
struct ISerialPort_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetSlot)(ISerialPort *pThis, PRUint32 *slot);

    nsresult PR_COM_METHOD (*GetEnabled)(ISerialPort *pThis, PRBool *enabled);
    nsresult PR_COM_METHOD (*SetEnabled)(ISerialPort *pThis, PRBool enabled);

    nsresult PR_COM_METHOD (*GetIOBase)(ISerialPort *pThis, PRUint32 *IOBase);
    nsresult PR_COM_METHOD (*SetIOBase)(ISerialPort *pThis, PRUint32 IOBase);

    nsresult PR_COM_METHOD (*GetIRQ)(ISerialPort *pThis, PRUint32 *IRQ);
    nsresult PR_COM_METHOD (*SetIRQ)(ISerialPort *pThis, PRUint32 IRQ);

    nsresult PR_COM_METHOD (*GetHostMode)(ISerialPort *pThis, PRUint32 *hostMode);
    nsresult PR_COM_METHOD (*SetHostMode)(ISerialPort *pThis, PRUint32 hostMode);

    nsresult PR_COM_METHOD (*GetServer)(ISerialPort *pThis, PRBool *server);
    nsresult PR_COM_METHOD (*SetServer)(ISerialPort *pThis, PRBool server);

    nsresult PR_COM_METHOD (*GetPath)(ISerialPort *pThis, PRUnichar * *path);
    nsresult PR_COM_METHOD (*SetPath)(ISerialPort *pThis, PRUnichar * path);

};

struct ISerialPort
{
    struct ISerialPort_vtbl *vtbl;
};
/* End of struct ISerialPort Declaration */


/* Start of struct IParallelPort Declaration */
#  define IPARALLELPORT_IID_STR "0c925f06-dd10-4b77-8de8-294d738c3214"
#  define IPARALLELPORT_IID { \
    0x0c925f06, 0xdd10, 0x4b77, \
    { 0x8d, 0xe8, 0x29, 0x4d, 0x73, 0x8c, 0x32, 0x14 } \
}
struct IParallelPort_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetSlot)(IParallelPort *pThis, PRUint32 *slot);

    nsresult PR_COM_METHOD (*GetEnabled)(IParallelPort *pThis, PRBool *enabled);
    nsresult PR_COM_METHOD (*SetEnabled)(IParallelPort *pThis, PRBool enabled);

    nsresult PR_COM_METHOD (*GetIOBase)(IParallelPort *pThis, PRUint32 *IOBase);
    nsresult PR_COM_METHOD (*SetIOBase)(IParallelPort *pThis, PRUint32 IOBase);

    nsresult PR_COM_METHOD (*GetIRQ)(IParallelPort *pThis, PRUint32 *IRQ);
    nsresult PR_COM_METHOD (*SetIRQ)(IParallelPort *pThis, PRUint32 IRQ);

    nsresult PR_COM_METHOD (*GetPath)(IParallelPort *pThis, PRUnichar * *path);
    nsresult PR_COM_METHOD (*SetPath)(IParallelPort *pThis, PRUnichar * path);

};

struct IParallelPort
{
    struct IParallelPort_vtbl *vtbl;
};
/* End of struct IParallelPort Declaration */


/* Start of struct IMachineDebugger Declaration */
#  define IMACHINEDEBUGGER_IID_STR "1bfd2fa9-0d91-44d3-9515-368dcbb3eb4d"
#  define IMACHINEDEBUGGER_IID { \
    0x1bfd2fa9, 0x0d91, 0x44d3, \
    { 0x95, 0x15, 0x36, 0x8d, 0xcb, 0xb3, 0xeb, 0x4d } \
}
struct IMachineDebugger_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetSinglestep)(IMachineDebugger *pThis, PRBool *singlestep);
    nsresult PR_COM_METHOD (*SetSinglestep)(IMachineDebugger *pThis, PRBool singlestep);

    nsresult PR_COM_METHOD (*GetRecompileUser)(IMachineDebugger *pThis, PRBool *recompileUser);
    nsresult PR_COM_METHOD (*SetRecompileUser)(IMachineDebugger *pThis, PRBool recompileUser);

    nsresult PR_COM_METHOD (*GetRecompileSupervisor)(IMachineDebugger *pThis, PRBool *recompileSupervisor);
    nsresult PR_COM_METHOD (*SetRecompileSupervisor)(IMachineDebugger *pThis, PRBool recompileSupervisor);

    nsresult PR_COM_METHOD (*GetPATMEnabled)(IMachineDebugger *pThis, PRBool *PATMEnabled);
    nsresult PR_COM_METHOD (*SetPATMEnabled)(IMachineDebugger *pThis, PRBool PATMEnabled);

    nsresult PR_COM_METHOD (*GetCSAMEnabled)(IMachineDebugger *pThis, PRBool *CSAMEnabled);
    nsresult PR_COM_METHOD (*SetCSAMEnabled)(IMachineDebugger *pThis, PRBool CSAMEnabled);

    nsresult PR_COM_METHOD (*GetLogEnabled)(IMachineDebugger *pThis, PRBool *logEnabled);
    nsresult PR_COM_METHOD (*SetLogEnabled)(IMachineDebugger *pThis, PRBool logEnabled);

    nsresult PR_COM_METHOD (*GetLogFlags)(IMachineDebugger *pThis, PRUnichar * *logFlags);

    nsresult PR_COM_METHOD (*GetLogGroups)(IMachineDebugger *pThis, PRUnichar * *logGroups);

    nsresult PR_COM_METHOD (*GetLogDestinations)(IMachineDebugger *pThis, PRUnichar * *logDestinations);

    nsresult PR_COM_METHOD (*GetHWVirtExEnabled)(IMachineDebugger *pThis, PRBool *HWVirtExEnabled);

    nsresult PR_COM_METHOD (*GetHWVirtExNestedPagingEnabled)(IMachineDebugger *pThis, PRBool *HWVirtExNestedPagingEnabled);

    nsresult PR_COM_METHOD (*GetHWVirtExVPIDEnabled)(IMachineDebugger *pThis, PRBool *HWVirtExVPIDEnabled);

    nsresult PR_COM_METHOD (*GetOSName)(IMachineDebugger *pThis, PRUnichar * *OSName);

    nsresult PR_COM_METHOD (*GetOSVersion)(IMachineDebugger *pThis, PRUnichar * *OSVersion);

    nsresult PR_COM_METHOD (*GetPAEEnabled)(IMachineDebugger *pThis, PRBool *PAEEnabled);

    nsresult PR_COM_METHOD (*GetVirtualTimeRate)(IMachineDebugger *pThis, PRUint32 *virtualTimeRate);
    nsresult PR_COM_METHOD (*SetVirtualTimeRate)(IMachineDebugger *pThis, PRUint32 virtualTimeRate);

    nsresult PR_COM_METHOD (*GetVM)(IMachineDebugger *pThis, PRInt64 *VM);

    nsresult PR_COM_METHOD (*DumpGuestCore)(
        IMachineDebugger *pThis,
        PRUnichar * filename,
        PRUnichar * compression
    );

    nsresult PR_COM_METHOD (*DumpHostProcessCore)(
        IMachineDebugger *pThis,
        PRUnichar * filename,
        PRUnichar * compression
    );

    nsresult PR_COM_METHOD (*Info)(
        IMachineDebugger *pThis,
        PRUnichar * name,
        PRUnichar * args,
        PRUnichar * * info
    );

    nsresult PR_COM_METHOD (*InjectNMI)(IMachineDebugger *pThis );

    nsresult PR_COM_METHOD (*ModifyLogGroups)(
        IMachineDebugger *pThis,
        PRUnichar * settings
    );

    nsresult PR_COM_METHOD (*ModifyLogFlags)(
        IMachineDebugger *pThis,
        PRUnichar * settings
    );

    nsresult PR_COM_METHOD (*ModifyLogDestinations)(
        IMachineDebugger *pThis,
        PRUnichar * settings
    );

    nsresult PR_COM_METHOD (*ReadPhysicalMemory)(
        IMachineDebugger *pThis,
        PRInt64 address,
        PRUint32 size,
        PRUint32 *bytesSize,
        PRUint8** bytes
    );

    nsresult PR_COM_METHOD (*WritePhysicalMemory)(
        IMachineDebugger *pThis,
        PRInt64 address,
        PRUint32 size,
        PRUint32 bytesSize,
        PRUint8* bytes
    );

    nsresult PR_COM_METHOD (*ReadVirtualMemory)(
        IMachineDebugger *pThis,
        PRUint32 cpuId,
        PRInt64 address,
        PRUint32 size,
        PRUint32 *bytesSize,
        PRUint8** bytes
    );

    nsresult PR_COM_METHOD (*WriteVirtualMemory)(
        IMachineDebugger *pThis,
        PRUint32 cpuId,
        PRInt64 address,
        PRUint32 size,
        PRUint32 bytesSize,
        PRUint8* bytes
    );

    nsresult PR_COM_METHOD (*DetectOS)(
        IMachineDebugger *pThis,
        PRUnichar * * os
    );

    nsresult PR_COM_METHOD (*GetRegister)(
        IMachineDebugger *pThis,
        PRUint32 cpuId,
        PRUnichar * name,
        PRUnichar * * value
    );

    nsresult PR_COM_METHOD (*GetRegisters)(
        IMachineDebugger *pThis,
        PRUint32 cpuId,
        PRUint32 *namesSize,
        PRUnichar *** names,
        PRUint32 *valuesSize,
        PRUnichar *** values
    );

    nsresult PR_COM_METHOD (*SetRegister)(
        IMachineDebugger *pThis,
        PRUint32 cpuId,
        PRUnichar * name,
        PRUnichar * value
    );

    nsresult PR_COM_METHOD (*SetRegisters)(
        IMachineDebugger *pThis,
        PRUint32 cpuId,
        PRUint32 namesSize,
        PRUnichar ** names,
        PRUint32 valuesSize,
        PRUnichar ** values
    );

    nsresult PR_COM_METHOD (*DumpGuestStack)(
        IMachineDebugger *pThis,
        PRUint32 cpuId,
        PRUnichar * * stack
    );

    nsresult PR_COM_METHOD (*ResetStats)(
        IMachineDebugger *pThis,
        PRUnichar * pattern
    );

    nsresult PR_COM_METHOD (*DumpStats)(
        IMachineDebugger *pThis,
        PRUnichar * pattern
    );

    nsresult PR_COM_METHOD (*GetStats)(
        IMachineDebugger *pThis,
        PRUnichar * pattern,
        PRBool withDescriptions,
        PRUnichar * * stats
    );

};

struct IMachineDebugger
{
    struct IMachineDebugger_vtbl *vtbl;
};
/* End of struct IMachineDebugger Declaration */


/* Start of struct IUSBController Declaration */
#  define IUSBCONTROLLER_IID_STR "6fdcccc5-abd3-4fec-9387-2ad3914fc4a8"
#  define IUSBCONTROLLER_IID { \
    0x6fdcccc5, 0xabd3, 0x4fec, \
    { 0x93, 0x87, 0x2a, 0xd3, 0x91, 0x4f, 0xc4, 0xa8 } \
}
struct IUSBController_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetEnabled)(IUSBController *pThis, PRBool *enabled);
    nsresult PR_COM_METHOD (*SetEnabled)(IUSBController *pThis, PRBool enabled);

    nsresult PR_COM_METHOD (*GetEnabledEhci)(IUSBController *pThis, PRBool *enabledEhci);
    nsresult PR_COM_METHOD (*SetEnabledEhci)(IUSBController *pThis, PRBool enabledEhci);

    nsresult PR_COM_METHOD (*GetProxyAvailable)(IUSBController *pThis, PRBool *proxyAvailable);

    nsresult PR_COM_METHOD (*GetUSBStandard)(IUSBController *pThis, PRUint16 *USBStandard);

    nsresult PR_COM_METHOD (*GetDeviceFilters)(IUSBController *pThis, PRUint32 *deviceFiltersSize, IUSBDeviceFilter * **deviceFilters);

    nsresult PR_COM_METHOD (*CreateDeviceFilter)(
        IUSBController *pThis,
        PRUnichar * name,
        IUSBDeviceFilter * * filter
    );

    nsresult PR_COM_METHOD (*InsertDeviceFilter)(
        IUSBController *pThis,
        PRUint32 position,
        IUSBDeviceFilter * filter
    );

    nsresult PR_COM_METHOD (*RemoveDeviceFilter)(
        IUSBController *pThis,
        PRUint32 position,
        IUSBDeviceFilter * * filter
    );

};

struct IUSBController
{
    struct IUSBController_vtbl *vtbl;
};
/* End of struct IUSBController Declaration */


/* Start of struct IUSBDevice Declaration */
#  define IUSBDEVICE_IID_STR "f8967b0b-4483-400f-92b5-8b675d98a85b"
#  define IUSBDEVICE_IID { \
    0xf8967b0b, 0x4483, 0x400f, \
    { 0x92, 0xb5, 0x8b, 0x67, 0x5d, 0x98, 0xa8, 0x5b } \
}
struct IUSBDevice_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetId)(IUSBDevice *pThis, PRUnichar * *id);

    nsresult PR_COM_METHOD (*GetVendorId)(IUSBDevice *pThis, PRUint16 *vendorId);

    nsresult PR_COM_METHOD (*GetProductId)(IUSBDevice *pThis, PRUint16 *productId);

    nsresult PR_COM_METHOD (*GetRevision)(IUSBDevice *pThis, PRUint16 *revision);

    nsresult PR_COM_METHOD (*GetManufacturer)(IUSBDevice *pThis, PRUnichar * *manufacturer);

    nsresult PR_COM_METHOD (*GetProduct)(IUSBDevice *pThis, PRUnichar * *product);

    nsresult PR_COM_METHOD (*GetSerialNumber)(IUSBDevice *pThis, PRUnichar * *serialNumber);

    nsresult PR_COM_METHOD (*GetAddress)(IUSBDevice *pThis, PRUnichar * *address);

    nsresult PR_COM_METHOD (*GetPort)(IUSBDevice *pThis, PRUint16 *port);

    nsresult PR_COM_METHOD (*GetVersion)(IUSBDevice *pThis, PRUint16 *version);

    nsresult PR_COM_METHOD (*GetPortVersion)(IUSBDevice *pThis, PRUint16 *portVersion);

    nsresult PR_COM_METHOD (*GetRemote)(IUSBDevice *pThis, PRBool *remote);

};

struct IUSBDevice
{
    struct IUSBDevice_vtbl *vtbl;
};
/* End of struct IUSBDevice Declaration */


/* Start of struct IUSBDeviceFilter Declaration */
#  define IUSBDEVICEFILTER_IID_STR "d6831fb4-1a94-4c2c-96ef-8d0d6192066d"
#  define IUSBDEVICEFILTER_IID { \
    0xd6831fb4, 0x1a94, 0x4c2c, \
    { 0x96, 0xef, 0x8d, 0x0d, 0x61, 0x92, 0x06, 0x6d } \
}
struct IUSBDeviceFilter_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetName)(IUSBDeviceFilter *pThis, PRUnichar * *name);
    nsresult PR_COM_METHOD (*SetName)(IUSBDeviceFilter *pThis, PRUnichar * name);

    nsresult PR_COM_METHOD (*GetActive)(IUSBDeviceFilter *pThis, PRBool *active);
    nsresult PR_COM_METHOD (*SetActive)(IUSBDeviceFilter *pThis, PRBool active);

    nsresult PR_COM_METHOD (*GetVendorId)(IUSBDeviceFilter *pThis, PRUnichar * *vendorId);
    nsresult PR_COM_METHOD (*SetVendorId)(IUSBDeviceFilter *pThis, PRUnichar * vendorId);

    nsresult PR_COM_METHOD (*GetProductId)(IUSBDeviceFilter *pThis, PRUnichar * *productId);
    nsresult PR_COM_METHOD (*SetProductId)(IUSBDeviceFilter *pThis, PRUnichar * productId);

    nsresult PR_COM_METHOD (*GetRevision)(IUSBDeviceFilter *pThis, PRUnichar * *revision);
    nsresult PR_COM_METHOD (*SetRevision)(IUSBDeviceFilter *pThis, PRUnichar * revision);

    nsresult PR_COM_METHOD (*GetManufacturer)(IUSBDeviceFilter *pThis, PRUnichar * *manufacturer);
    nsresult PR_COM_METHOD (*SetManufacturer)(IUSBDeviceFilter *pThis, PRUnichar * manufacturer);

    nsresult PR_COM_METHOD (*GetProduct)(IUSBDeviceFilter *pThis, PRUnichar * *product);
    nsresult PR_COM_METHOD (*SetProduct)(IUSBDeviceFilter *pThis, PRUnichar * product);

    nsresult PR_COM_METHOD (*GetSerialNumber)(IUSBDeviceFilter *pThis, PRUnichar * *serialNumber);
    nsresult PR_COM_METHOD (*SetSerialNumber)(IUSBDeviceFilter *pThis, PRUnichar * serialNumber);

    nsresult PR_COM_METHOD (*GetPort)(IUSBDeviceFilter *pThis, PRUnichar * *port);
    nsresult PR_COM_METHOD (*SetPort)(IUSBDeviceFilter *pThis, PRUnichar * port);

    nsresult PR_COM_METHOD (*GetRemote)(IUSBDeviceFilter *pThis, PRUnichar * *remote);
    nsresult PR_COM_METHOD (*SetRemote)(IUSBDeviceFilter *pThis, PRUnichar * remote);

    nsresult PR_COM_METHOD (*GetMaskedInterfaces)(IUSBDeviceFilter *pThis, PRUint32 *maskedInterfaces);
    nsresult PR_COM_METHOD (*SetMaskedInterfaces)(IUSBDeviceFilter *pThis, PRUint32 maskedInterfaces);

};

struct IUSBDeviceFilter
{
    struct IUSBDeviceFilter_vtbl *vtbl;
};
/* End of struct IUSBDeviceFilter Declaration */


/* Start of struct IHostUSBDevice Declaration */
#  define IHOSTUSBDEVICE_IID_STR "173b4b44-d268-4334-a00d-b6521c9a740a"
#  define IHOSTUSBDEVICE_IID { \
    0x173b4b44, 0xd268, 0x4334, \
    { 0xa0, 0x0d, 0xb6, 0x52, 0x1c, 0x9a, 0x74, 0x0a } \
}
struct IHostUSBDevice_vtbl
{
    struct IUSBDevice_vtbl iusbdevice;

    nsresult PR_COM_METHOD (*GetState)(IHostUSBDevice *pThis, PRUint32 *state);

};

struct IHostUSBDevice
{
    struct IHostUSBDevice_vtbl *vtbl;
};
/* End of struct IHostUSBDevice Declaration */


/* Start of struct IHostUSBDeviceFilter Declaration */
#  define IHOSTUSBDEVICEFILTER_IID_STR "4cc70246-d74a-400f-8222-3900489c0374"
#  define IHOSTUSBDEVICEFILTER_IID { \
    0x4cc70246, 0xd74a, 0x400f, \
    { 0x82, 0x22, 0x39, 0x00, 0x48, 0x9c, 0x03, 0x74 } \
}
struct IHostUSBDeviceFilter_vtbl
{
    struct IUSBDeviceFilter_vtbl iusbdevicefilter;

    nsresult PR_COM_METHOD (*GetAction)(IHostUSBDeviceFilter *pThis, PRUint32 *action);
    nsresult PR_COM_METHOD (*SetAction)(IHostUSBDeviceFilter *pThis, PRUint32 action);

};

struct IHostUSBDeviceFilter
{
    struct IHostUSBDeviceFilter_vtbl *vtbl;
};
/* End of struct IHostUSBDeviceFilter Declaration */


/* Start of struct IAudioAdapter Declaration */
#  define IAUDIOADAPTER_IID_STR "921873db-5f3f-4b69-91f9-7be9e535a2cb"
#  define IAUDIOADAPTER_IID { \
    0x921873db, 0x5f3f, 0x4b69, \
    { 0x91, 0xf9, 0x7b, 0xe9, 0xe5, 0x35, 0xa2, 0xcb } \
}
struct IAudioAdapter_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetEnabled)(IAudioAdapter *pThis, PRBool *enabled);
    nsresult PR_COM_METHOD (*SetEnabled)(IAudioAdapter *pThis, PRBool enabled);

    nsresult PR_COM_METHOD (*GetAudioController)(IAudioAdapter *pThis, PRUint32 *audioController);
    nsresult PR_COM_METHOD (*SetAudioController)(IAudioAdapter *pThis, PRUint32 audioController);

    nsresult PR_COM_METHOD (*GetAudioDriver)(IAudioAdapter *pThis, PRUint32 *audioDriver);
    nsresult PR_COM_METHOD (*SetAudioDriver)(IAudioAdapter *pThis, PRUint32 audioDriver);

};

struct IAudioAdapter
{
    struct IAudioAdapter_vtbl *vtbl;
};
/* End of struct IAudioAdapter Declaration */


/* Start of struct IVRDEServer Declaration */
#  define IVRDESERVER_IID_STR "be24e0db-e1d6-4d58-b85b-21053d1511b4"
#  define IVRDESERVER_IID { \
    0xbe24e0db, 0xe1d6, 0x4d58, \
    { 0xb8, 0x5b, 0x21, 0x05, 0x3d, 0x15, 0x11, 0xb4 } \
}
struct IVRDEServer_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetEnabled)(IVRDEServer *pThis, PRBool *enabled);
    nsresult PR_COM_METHOD (*SetEnabled)(IVRDEServer *pThis, PRBool enabled);

    nsresult PR_COM_METHOD (*GetAuthType)(IVRDEServer *pThis, PRUint32 *authType);
    nsresult PR_COM_METHOD (*SetAuthType)(IVRDEServer *pThis, PRUint32 authType);

    nsresult PR_COM_METHOD (*GetAuthTimeout)(IVRDEServer *pThis, PRUint32 *authTimeout);
    nsresult PR_COM_METHOD (*SetAuthTimeout)(IVRDEServer *pThis, PRUint32 authTimeout);

    nsresult PR_COM_METHOD (*GetAllowMultiConnection)(IVRDEServer *pThis, PRBool *allowMultiConnection);
    nsresult PR_COM_METHOD (*SetAllowMultiConnection)(IVRDEServer *pThis, PRBool allowMultiConnection);

    nsresult PR_COM_METHOD (*GetReuseSingleConnection)(IVRDEServer *pThis, PRBool *reuseSingleConnection);
    nsresult PR_COM_METHOD (*SetReuseSingleConnection)(IVRDEServer *pThis, PRBool reuseSingleConnection);

    nsresult PR_COM_METHOD (*GetVRDEExtPack)(IVRDEServer *pThis, PRUnichar * *VRDEExtPack);
    nsresult PR_COM_METHOD (*SetVRDEExtPack)(IVRDEServer *pThis, PRUnichar * VRDEExtPack);

    nsresult PR_COM_METHOD (*GetAuthLibrary)(IVRDEServer *pThis, PRUnichar * *AuthLibrary);
    nsresult PR_COM_METHOD (*SetAuthLibrary)(IVRDEServer *pThis, PRUnichar * AuthLibrary);

    nsresult PR_COM_METHOD (*GetVRDEProperties)(IVRDEServer *pThis, PRUint32 *VRDEPropertiesSize, PRUnichar * **VRDEProperties);

    nsresult PR_COM_METHOD (*SetVRDEProperty)(
        IVRDEServer *pThis,
        PRUnichar * key,
        PRUnichar * value
    );

    nsresult PR_COM_METHOD (*GetVRDEProperty)(
        IVRDEServer *pThis,
        PRUnichar * key,
        PRUnichar * * value
    );

};

struct IVRDEServer
{
    struct IVRDEServer_vtbl *vtbl;
};
/* End of struct IVRDEServer Declaration */


/* Start of struct ISharedFolder Declaration */
#  define ISHAREDFOLDER_IID_STR "8388da11-b559-4574-a5b7-2bd7acd5cef8"
#  define ISHAREDFOLDER_IID { \
    0x8388da11, 0xb559, 0x4574, \
    { 0xa5, 0xb7, 0x2b, 0xd7, 0xac, 0xd5, 0xce, 0xf8 } \
}
struct ISharedFolder_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetName)(ISharedFolder *pThis, PRUnichar * *name);

    nsresult PR_COM_METHOD (*GetHostPath)(ISharedFolder *pThis, PRUnichar * *hostPath);

    nsresult PR_COM_METHOD (*GetAccessible)(ISharedFolder *pThis, PRBool *accessible);

    nsresult PR_COM_METHOD (*GetWritable)(ISharedFolder *pThis, PRBool *writable);

    nsresult PR_COM_METHOD (*GetAutoMount)(ISharedFolder *pThis, PRBool *autoMount);

    nsresult PR_COM_METHOD (*GetLastAccessError)(ISharedFolder *pThis, PRUnichar * *lastAccessError);

};

struct ISharedFolder
{
    struct ISharedFolder_vtbl *vtbl;
};
/* End of struct ISharedFolder Declaration */


/* Start of struct IInternalSessionControl Declaration */
#  define IINTERNALSESSIONCONTROL_IID_STR "a2fbf834-149d-41da-ae52-0dc3b0f032b3"
#  define IINTERNALSESSIONCONTROL_IID { \
    0xa2fbf834, 0x149d, 0x41da, \
    { 0xae, 0x52, 0x0d, 0xc3, 0xb0, 0xf0, 0x32, 0xb3 } \
}
struct IInternalSessionControl_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetPID)(
        IInternalSessionControl *pThis,
        PRUint32 * pid
    );

    nsresult PR_COM_METHOD (*GetRemoteConsole)(
        IInternalSessionControl *pThis,
        IConsole * * console
    );

    nsresult PR_COM_METHOD (*AssignMachine)(
        IInternalSessionControl *pThis,
        IMachine * machine
    );

    nsresult PR_COM_METHOD (*AssignRemoteMachine)(
        IInternalSessionControl *pThis,
        IMachine * machine,
        IConsole * console
    );

    nsresult PR_COM_METHOD (*UpdateMachineState)(
        IInternalSessionControl *pThis,
        PRUint32 aMachineState
    );

    nsresult PR_COM_METHOD (*Uninitialize)(IInternalSessionControl *pThis );

    nsresult PR_COM_METHOD (*OnNetworkAdapterChange)(
        IInternalSessionControl *pThis,
        INetworkAdapter * networkAdapter,
        PRBool changeAdapter
    );

    nsresult PR_COM_METHOD (*OnSerialPortChange)(
        IInternalSessionControl *pThis,
        ISerialPort * serialPort
    );

    nsresult PR_COM_METHOD (*OnParallelPortChange)(
        IInternalSessionControl *pThis,
        IParallelPort * parallelPort
    );

    nsresult PR_COM_METHOD (*OnStorageControllerChange)(IInternalSessionControl *pThis );

    nsresult PR_COM_METHOD (*OnMediumChange)(
        IInternalSessionControl *pThis,
        IMediumAttachment * mediumAttachment,
        PRBool force
    );

    nsresult PR_COM_METHOD (*OnCPUChange)(
        IInternalSessionControl *pThis,
        PRUint32 cpu,
        PRBool add
    );

    nsresult PR_COM_METHOD (*OnCPUExecutionCapChange)(
        IInternalSessionControl *pThis,
        PRUint32 executionCap
    );

    nsresult PR_COM_METHOD (*OnVRDEServerChange)(
        IInternalSessionControl *pThis,
        PRBool restart
    );

    nsresult PR_COM_METHOD (*OnUSBControllerChange)(IInternalSessionControl *pThis );

    nsresult PR_COM_METHOD (*OnSharedFolderChange)(
        IInternalSessionControl *pThis,
        PRBool global
    );

    nsresult PR_COM_METHOD (*OnUSBDeviceAttach)(
        IInternalSessionControl *pThis,
        IUSBDevice * device,
        IVirtualBoxErrorInfo * error,
        PRUint32 maskedInterfaces
    );

    nsresult PR_COM_METHOD (*OnUSBDeviceDetach)(
        IInternalSessionControl *pThis,
        PRUnichar * id,
        IVirtualBoxErrorInfo * error
    );

    nsresult PR_COM_METHOD (*OnShowWindow)(
        IInternalSessionControl *pThis,
        PRBool check,
        PRBool * canShow,
        PRInt64 * winId
    );

    nsresult PR_COM_METHOD (*OnBandwidthGroupChange)(
        IInternalSessionControl *pThis,
        IBandwidthGroup * bandwidthGroup
    );

    nsresult PR_COM_METHOD (*AccessGuestProperty)(
        IInternalSessionControl *pThis,
        PRUnichar * name,
        PRUnichar * value,
        PRUnichar * flags,
        PRBool isSetter,
        PRUnichar * * retValue,
        PRInt64 * retTimestamp,
        PRUnichar * * retFlags
    );

    nsresult PR_COM_METHOD (*EnumerateGuestProperties)(
        IInternalSessionControl *pThis,
        PRUnichar * patterns,
        PRUint32 *keySize,
        PRUnichar *** key,
        PRUint32 *valueSize,
        PRUnichar *** value,
        PRUint32 *timestampSize,
        PRInt64* timestamp,
        PRUint32 *flagsSize,
        PRUnichar *** flags
    );

    nsresult PR_COM_METHOD (*OnlineMergeMedium)(
        IInternalSessionControl *pThis,
        IMediumAttachment * mediumAttachment,
        PRUint32 sourceIdx,
        PRUint32 targetIdx,
        IMedium * source,
        IMedium * target,
        PRBool mergeForward,
        IMedium * parentForTarget,
        PRUint32 childrenToReparentSize,
        IMedium ** childrenToReparent,
        IProgress * progress
    );

};

struct IInternalSessionControl
{
    struct IInternalSessionControl_vtbl *vtbl;
};
/* End of struct IInternalSessionControl Declaration */


/* Start of struct ISession Declaration */
#  define ISESSION_IID_STR "12F4DCDB-12B2-4EC1-B7CD-DDD9F6C5BF4D"
#  define ISESSION_IID { \
    0x12F4DCDB, 0x12B2, 0x4EC1, \
    { 0xB7, 0xCD, 0xDD, 0xD9, 0xF6, 0xC5, 0xBF, 0x4D } \
}
struct ISession_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetState)(ISession *pThis, PRUint32 *state);

    nsresult PR_COM_METHOD (*GetType)(ISession *pThis, PRUint32 *type);

    nsresult PR_COM_METHOD (*GetMachine)(ISession *pThis, IMachine * *machine);

    nsresult PR_COM_METHOD (*GetConsole)(ISession *pThis, IConsole * *console);

    nsresult PR_COM_METHOD (*UnlockMachine)(ISession *pThis );

};

struct ISession
{
    struct ISession_vtbl *vtbl;
};
/* End of struct ISession Declaration */


/* Start of struct IStorageController Declaration */
#  define ISTORAGECONTROLLER_IID_STR "a1556333-09b6-46d9-bfb7-fc239b7fbe1e"
#  define ISTORAGECONTROLLER_IID { \
    0xa1556333, 0x09b6, 0x46d9, \
    { 0xbf, 0xb7, 0xfc, 0x23, 0x9b, 0x7f, 0xbe, 0x1e } \
}
struct IStorageController_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetName)(IStorageController *pThis, PRUnichar * *name);

    nsresult PR_COM_METHOD (*GetMaxDevicesPerPortCount)(IStorageController *pThis, PRUint32 *maxDevicesPerPortCount);

    nsresult PR_COM_METHOD (*GetMinPortCount)(IStorageController *pThis, PRUint32 *minPortCount);

    nsresult PR_COM_METHOD (*GetMaxPortCount)(IStorageController *pThis, PRUint32 *maxPortCount);

    nsresult PR_COM_METHOD (*GetInstance)(IStorageController *pThis, PRUint32 *instance);
    nsresult PR_COM_METHOD (*SetInstance)(IStorageController *pThis, PRUint32 instance);

    nsresult PR_COM_METHOD (*GetPortCount)(IStorageController *pThis, PRUint32 *portCount);
    nsresult PR_COM_METHOD (*SetPortCount)(IStorageController *pThis, PRUint32 portCount);

    nsresult PR_COM_METHOD (*GetBus)(IStorageController *pThis, PRUint32 *bus);

    nsresult PR_COM_METHOD (*GetControllerType)(IStorageController *pThis, PRUint32 *controllerType);
    nsresult PR_COM_METHOD (*SetControllerType)(IStorageController *pThis, PRUint32 controllerType);

    nsresult PR_COM_METHOD (*GetUseHostIOCache)(IStorageController *pThis, PRBool *useHostIOCache);
    nsresult PR_COM_METHOD (*SetUseHostIOCache)(IStorageController *pThis, PRBool useHostIOCache);

    nsresult PR_COM_METHOD (*GetBootable)(IStorageController *pThis, PRBool *bootable);

    nsresult PR_COM_METHOD (*GetIDEEmulationPort)(
        IStorageController *pThis,
        PRInt32 devicePosition,
        PRInt32 * portNumber
    );

    nsresult PR_COM_METHOD (*SetIDEEmulationPort)(
        IStorageController *pThis,
        PRInt32 devicePosition,
        PRInt32 portNumber
    );

};

struct IStorageController
{
    struct IStorageController_vtbl *vtbl;
};
/* End of struct IStorageController Declaration */


/* Start of struct IPerformanceMetric Declaration */
#  define IPERFORMANCEMETRIC_IID_STR "2a1a60ae-9345-4019-ad53-d34ba41cbfe9"
#  define IPERFORMANCEMETRIC_IID { \
    0x2a1a60ae, 0x9345, 0x4019, \
    { 0xad, 0x53, 0xd3, 0x4b, 0xa4, 0x1c, 0xbf, 0xe9 } \
}
struct IPerformanceMetric_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetMetricName)(IPerformanceMetric *pThis, PRUnichar * *metricName);

    nsresult PR_COM_METHOD (*GetObject)(IPerformanceMetric *pThis, nsISupports * *object);

    nsresult PR_COM_METHOD (*GetDescription)(IPerformanceMetric *pThis, PRUnichar * *description);

    nsresult PR_COM_METHOD (*GetPeriod)(IPerformanceMetric *pThis, PRUint32 *period);

    nsresult PR_COM_METHOD (*GetCount)(IPerformanceMetric *pThis, PRUint32 *count);

    nsresult PR_COM_METHOD (*GetUnit)(IPerformanceMetric *pThis, PRUnichar * *unit);

    nsresult PR_COM_METHOD (*GetMinimumValue)(IPerformanceMetric *pThis, PRInt32 *minimumValue);

    nsresult PR_COM_METHOD (*GetMaximumValue)(IPerformanceMetric *pThis, PRInt32 *maximumValue);

};

struct IPerformanceMetric
{
    struct IPerformanceMetric_vtbl *vtbl;
};
/* End of struct IPerformanceMetric Declaration */


/* Start of struct IPerformanceCollector Declaration */
#  define IPERFORMANCECOLLECTOR_IID_STR "e22e1acb-ac4a-43bb-a31c-17321659b0c6"
#  define IPERFORMANCECOLLECTOR_IID { \
    0xe22e1acb, 0xac4a, 0x43bb, \
    { 0xa3, 0x1c, 0x17, 0x32, 0x16, 0x59, 0xb0, 0xc6 } \
}
struct IPerformanceCollector_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetMetricNames)(IPerformanceCollector *pThis, PRUint32 *metricNamesSize, PRUnichar * **metricNames);

    nsresult PR_COM_METHOD (*GetMetrics)(
        IPerformanceCollector *pThis,
        PRUint32 metricNamesSize,
        PRUnichar ** metricNames,
        PRUint32 objectsSize,
        nsISupports ** objects,
        PRUint32 *metricsSize,
        IPerformanceMetric *** metrics
    );

    nsresult PR_COM_METHOD (*SetupMetrics)(
        IPerformanceCollector *pThis,
        PRUint32 metricNamesSize,
        PRUnichar ** metricNames,
        PRUint32 objectsSize,
        nsISupports ** objects,
        PRUint32 period,
        PRUint32 count,
        PRUint32 *affectedMetricsSize,
        IPerformanceMetric *** affectedMetrics
    );

    nsresult PR_COM_METHOD (*EnableMetrics)(
        IPerformanceCollector *pThis,
        PRUint32 metricNamesSize,
        PRUnichar ** metricNames,
        PRUint32 objectsSize,
        nsISupports ** objects,
        PRUint32 *affectedMetricsSize,
        IPerformanceMetric *** affectedMetrics
    );

    nsresult PR_COM_METHOD (*DisableMetrics)(
        IPerformanceCollector *pThis,
        PRUint32 metricNamesSize,
        PRUnichar ** metricNames,
        PRUint32 objectsSize,
        nsISupports ** objects,
        PRUint32 *affectedMetricsSize,
        IPerformanceMetric *** affectedMetrics
    );

    nsresult PR_COM_METHOD (*QueryMetricsData)(
        IPerformanceCollector *pThis,
        PRUint32 metricNamesSize,
        PRUnichar ** metricNames,
        PRUint32 objectsSize,
        nsISupports ** objects,
        PRUint32 *returnMetricNamesSize,
        PRUnichar *** returnMetricNames,
        PRUint32 *returnObjectsSize,
        nsISupports ** returnObjects,
        PRUint32 *returnUnitsSize,
        PRUnichar *** returnUnits,
        PRUint32 *returnScalesSize,
        PRUint32* returnScales,
        PRUint32 *returnSequenceNumbersSize,
        PRUint32* returnSequenceNumbers,
        PRUint32 *returnDataIndicesSize,
        PRUint32* returnDataIndices,
        PRUint32 *returnDataLengthsSize,
        PRUint32* returnDataLengths,
        PRUint32 *returnDataSize,
        PRInt32** returnData
    );

};

struct IPerformanceCollector
{
    struct IPerformanceCollector_vtbl *vtbl;
};
/* End of struct IPerformanceCollector Declaration */


/* Start of struct INATEngine Declaration */
#  define INATENGINE_IID_STR "4b286616-eb03-11de-b0fb-1701eca42246"
#  define INATENGINE_IID { \
    0x4b286616, 0xeb03, 0x11de, \
    { 0xb0, 0xfb, 0x17, 0x01, 0xec, 0xa4, 0x22, 0x46 } \
}
struct INATEngine_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetNetwork)(INATEngine *pThis, PRUnichar * *network);
    nsresult PR_COM_METHOD (*SetNetwork)(INATEngine *pThis, PRUnichar * network);

    nsresult PR_COM_METHOD (*GetHostIP)(INATEngine *pThis, PRUnichar * *hostIP);
    nsresult PR_COM_METHOD (*SetHostIP)(INATEngine *pThis, PRUnichar * hostIP);

    nsresult PR_COM_METHOD (*GetTftpPrefix)(INATEngine *pThis, PRUnichar * *tftpPrefix);
    nsresult PR_COM_METHOD (*SetTftpPrefix)(INATEngine *pThis, PRUnichar * tftpPrefix);

    nsresult PR_COM_METHOD (*GetTftpBootFile)(INATEngine *pThis, PRUnichar * *tftpBootFile);
    nsresult PR_COM_METHOD (*SetTftpBootFile)(INATEngine *pThis, PRUnichar * tftpBootFile);

    nsresult PR_COM_METHOD (*GetTftpNextServer)(INATEngine *pThis, PRUnichar * *tftpNextServer);
    nsresult PR_COM_METHOD (*SetTftpNextServer)(INATEngine *pThis, PRUnichar * tftpNextServer);

    nsresult PR_COM_METHOD (*GetAliasMode)(INATEngine *pThis, PRUint32 *aliasMode);
    nsresult PR_COM_METHOD (*SetAliasMode)(INATEngine *pThis, PRUint32 aliasMode);

    nsresult PR_COM_METHOD (*GetDnsPassDomain)(INATEngine *pThis, PRBool *dnsPassDomain);
    nsresult PR_COM_METHOD (*SetDnsPassDomain)(INATEngine *pThis, PRBool dnsPassDomain);

    nsresult PR_COM_METHOD (*GetDnsProxy)(INATEngine *pThis, PRBool *dnsProxy);
    nsresult PR_COM_METHOD (*SetDnsProxy)(INATEngine *pThis, PRBool dnsProxy);

    nsresult PR_COM_METHOD (*GetDnsUseHostResolver)(INATEngine *pThis, PRBool *dnsUseHostResolver);
    nsresult PR_COM_METHOD (*SetDnsUseHostResolver)(INATEngine *pThis, PRBool dnsUseHostResolver);

    nsresult PR_COM_METHOD (*GetRedirects)(INATEngine *pThis, PRUint32 *redirectsSize, PRUnichar * **redirects);

    nsresult PR_COM_METHOD (*SetNetworkSettings)(
        INATEngine *pThis,
        PRUint32 mtu,
        PRUint32 sockSnd,
        PRUint32 sockRcv,
        PRUint32 TcpWndSnd,
        PRUint32 TcpWndRcv
    );

    nsresult PR_COM_METHOD (*GetNetworkSettings)(
        INATEngine *pThis,
        PRUint32 * mtu,
        PRUint32 * sockSnd,
        PRUint32 * sockRcv,
        PRUint32 * TcpWndSnd,
        PRUint32 * TcpWndRcv
    );

    nsresult PR_COM_METHOD (*AddRedirect)(
        INATEngine *pThis,
        PRUnichar * name,
        PRUint32 proto,
        PRUnichar * hostIp,
        PRUint16 hostPort,
        PRUnichar * guestIp,
        PRUint16 guestPort
    );

    nsresult PR_COM_METHOD (*RemoveRedirect)(
        INATEngine *pThis,
        PRUnichar * name
    );

};

struct INATEngine
{
    struct INATEngine_vtbl *vtbl;
};
/* End of struct INATEngine Declaration */


/* Start of struct IExtPackPlugIn Declaration */
#  define IEXTPACKPLUGIN_IID_STR "58000040-e718-4746-bbce-4b86d96da461"
#  define IEXTPACKPLUGIN_IID { \
    0x58000040, 0xe718, 0x4746, \
    { 0xbb, 0xce, 0x4b, 0x86, 0xd9, 0x6d, 0xa4, 0x61 } \
}
struct IExtPackPlugIn_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetName)(IExtPackPlugIn *pThis, PRUnichar * *name);

    nsresult PR_COM_METHOD (*GetDescription)(IExtPackPlugIn *pThis, PRUnichar * *description);

    nsresult PR_COM_METHOD (*GetFrontend)(IExtPackPlugIn *pThis, PRUnichar * *frontend);

    nsresult PR_COM_METHOD (*GetModulePath)(IExtPackPlugIn *pThis, PRUnichar * *modulePath);

};

struct IExtPackPlugIn
{
    struct IExtPackPlugIn_vtbl *vtbl;
};
/* End of struct IExtPackPlugIn Declaration */


/* Start of struct IExtPackBase Declaration */
#  define IEXTPACKBASE_IID_STR "5ffb0b64-0ad6-467d-af62-1157e7dc3c99"
#  define IEXTPACKBASE_IID { \
    0x5ffb0b64, 0x0ad6, 0x467d, \
    { 0xaf, 0x62, 0x11, 0x57, 0xe7, 0xdc, 0x3c, 0x99 } \
}
struct IExtPackBase_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetName)(IExtPackBase *pThis, PRUnichar * *name);

    nsresult PR_COM_METHOD (*GetDescription)(IExtPackBase *pThis, PRUnichar * *description);

    nsresult PR_COM_METHOD (*GetVersion)(IExtPackBase *pThis, PRUnichar * *version);

    nsresult PR_COM_METHOD (*GetRevision)(IExtPackBase *pThis, PRUint32 *revision);

    nsresult PR_COM_METHOD (*GetVRDEModule)(IExtPackBase *pThis, PRUnichar * *VRDEModule);

    nsresult PR_COM_METHOD (*GetPlugIns)(IExtPackBase *pThis, PRUint32 *plugInsSize, IExtPackPlugIn * **plugIns);

    nsresult PR_COM_METHOD (*GetUsable)(IExtPackBase *pThis, PRBool *usable);

    nsresult PR_COM_METHOD (*GetWhyUnusable)(IExtPackBase *pThis, PRUnichar * *whyUnusable);

    nsresult PR_COM_METHOD (*GetShowLicense)(IExtPackBase *pThis, PRBool *showLicense);

    nsresult PR_COM_METHOD (*GetLicense)(IExtPackBase *pThis, PRUnichar * *license);

    nsresult PR_COM_METHOD (*QueryLicense)(
        IExtPackBase *pThis,
        PRUnichar * preferredLocale,
        PRUnichar * preferredLanguage,
        PRUnichar * format,
        PRUnichar * * licenseText
    );

};

struct IExtPackBase
{
    struct IExtPackBase_vtbl *vtbl;
};
/* End of struct IExtPackBase Declaration */


/* Start of struct IExtPack Declaration */
#  define IEXTPACK_IID_STR "431685da-3618-4ebc-b038-833ba829b4b2"
#  define IEXTPACK_IID { \
    0x431685da, 0x3618, 0x4ebc, \
    { 0xb0, 0x38, 0x83, 0x3b, 0xa8, 0x29, 0xb4, 0xb2 } \
}
struct IExtPack_vtbl
{
    struct IExtPackBase_vtbl iextpackbase;

    nsresult PR_COM_METHOD (*QueryObject)(
        IExtPack *pThis,
        PRUnichar * objUuid,
        nsISupports * * returnInterface
    );

};

struct IExtPack
{
    struct IExtPack_vtbl *vtbl;
};
/* End of struct IExtPack Declaration */


/* Start of struct IExtPackFile Declaration */
#  define IEXTPACKFILE_IID_STR "b6b49f55-efcc-4f08-b486-56e8d8afb10b"
#  define IEXTPACKFILE_IID { \
    0xb6b49f55, 0xefcc, 0x4f08, \
    { 0xb4, 0x86, 0x56, 0xe8, 0xd8, 0xaf, 0xb1, 0x0b } \
}
struct IExtPackFile_vtbl
{
    struct IExtPackBase_vtbl iextpackbase;

    nsresult PR_COM_METHOD (*GetFilePath)(IExtPackFile *pThis, PRUnichar * *filePath);

    nsresult PR_COM_METHOD (*Install)(
        IExtPackFile *pThis,
        PRBool replace,
        PRUnichar * displayInfo,
        IProgress * * progess
    );

};

struct IExtPackFile
{
    struct IExtPackFile_vtbl *vtbl;
};
/* End of struct IExtPackFile Declaration */


/* Start of struct IExtPackManager Declaration */
#  define IEXTPACKMANAGER_IID_STR "2451b1ba-ab1c-42fb-b453-c58433bea8c7"
#  define IEXTPACKMANAGER_IID { \
    0x2451b1ba, 0xab1c, 0x42fb, \
    { 0xb4, 0x53, 0xc5, 0x84, 0x33, 0xbe, 0xa8, 0xc7 } \
}
struct IExtPackManager_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetInstalledExtPacks)(IExtPackManager *pThis, PRUint32 *installedExtPacksSize, IExtPack * **installedExtPacks);

    nsresult PR_COM_METHOD (*Find)(
        IExtPackManager *pThis,
        PRUnichar * name,
        IExtPack * * returnData
    );

    nsresult PR_COM_METHOD (*OpenExtPackFile)(
        IExtPackManager *pThis,
        PRUnichar * path,
        IExtPackFile * * file
    );

    nsresult PR_COM_METHOD (*Uninstall)(
        IExtPackManager *pThis,
        PRUnichar * name,
        PRBool forcedRemoval,
        PRUnichar * displayInfo,
        IProgress * * progess
    );

    nsresult PR_COM_METHOD (*Cleanup)(IExtPackManager *pThis );

    nsresult PR_COM_METHOD (*QueryAllPlugInsForFrontend)(
        IExtPackManager *pThis,
        PRUnichar * frontendName,
        PRUint32 *plugInModulesSize,
        PRUnichar *** plugInModules
    );

    nsresult PR_COM_METHOD (*IsExtPackUsable)(
        IExtPackManager *pThis,
        PRUnichar * name,
        PRBool * usable
    );

};

struct IExtPackManager
{
    struct IExtPackManager_vtbl *vtbl;
};
/* End of struct IExtPackManager Declaration */


/* Start of struct IBandwidthGroup Declaration */
#  define IBANDWIDTHGROUP_IID_STR "badea2d7-0261-4146-89f0-6a57cc34833d"
#  define IBANDWIDTHGROUP_IID { \
    0xbadea2d7, 0x0261, 0x4146, \
    { 0x89, 0xf0, 0x6a, 0x57, 0xcc, 0x34, 0x83, 0x3d } \
}
struct IBandwidthGroup_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetName)(IBandwidthGroup *pThis, PRUnichar * *name);

    nsresult PR_COM_METHOD (*GetType)(IBandwidthGroup *pThis, PRUint32 *type);

    nsresult PR_COM_METHOD (*GetReference)(IBandwidthGroup *pThis, PRUint32 *reference);

    nsresult PR_COM_METHOD (*GetMaxMbPerSec)(IBandwidthGroup *pThis, PRUint32 *maxMbPerSec);
    nsresult PR_COM_METHOD (*SetMaxMbPerSec)(IBandwidthGroup *pThis, PRUint32 maxMbPerSec);

};

struct IBandwidthGroup
{
    struct IBandwidthGroup_vtbl *vtbl;
};
/* End of struct IBandwidthGroup Declaration */


/* Start of struct IBandwidthControl Declaration */
#  define IBANDWIDTHCONTROL_IID_STR "d0a24db0-f756-11df-98cf-0800200c9a66"
#  define IBANDWIDTHCONTROL_IID { \
    0xd0a24db0, 0xf756, 0x11df, \
    { 0x98, 0xcf, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 } \
}
struct IBandwidthControl_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetNumGroups)(IBandwidthControl *pThis, PRUint32 *numGroups);

    nsresult PR_COM_METHOD (*CreateBandwidthGroup)(
        IBandwidthControl *pThis,
        PRUnichar * name,
        PRUint32 type,
        PRUint32 maxBytesPerSec
    );

    nsresult PR_COM_METHOD (*DeleteBandwidthGroup)(
        IBandwidthControl *pThis,
        PRUnichar * name
    );

    nsresult PR_COM_METHOD (*GetBandwidthGroup)(
        IBandwidthControl *pThis,
        PRUnichar * name,
        IBandwidthGroup * * bandwidthGroup
    );

    nsresult PR_COM_METHOD (*GetAllBandwidthGroups)(
        IBandwidthControl *pThis,
        PRUint32 *bandwidthGroupsSize,
        IBandwidthGroup *** bandwidthGroups
    );

};

struct IBandwidthControl
{
    struct IBandwidthControl_vtbl *vtbl;
};
/* End of struct IBandwidthControl Declaration */


/* Start of struct IVirtualBoxClient Declaration */
#  define IVIRTUALBOXCLIENT_IID_STR "5fe0bd48-1181-40d1-991f-3b02f269a823"
#  define IVIRTUALBOXCLIENT_IID { \
    0x5fe0bd48, 0x1181, 0x40d1, \
    { 0x99, 0x1f, 0x3b, 0x02, 0xf2, 0x69, 0xa8, 0x23 } \
}
struct IVirtualBoxClient_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetVirtualBox)(IVirtualBoxClient *pThis, IVirtualBox * *virtualBox);

    nsresult PR_COM_METHOD (*GetSession)(IVirtualBoxClient *pThis, ISession * *session);

    nsresult PR_COM_METHOD (*GetEventSource)(IVirtualBoxClient *pThis, IEventSource * *eventSource);

};

struct IVirtualBoxClient
{
    struct IVirtualBoxClient_vtbl *vtbl;
};
/* End of struct IVirtualBoxClient Declaration */


/* Start of struct IEventSource Declaration */
#  define IEVENTSOURCE_IID_STR "9b6e1aee-35f3-4f4d-b5bb-ed0ecefd8538"
#  define IEVENTSOURCE_IID { \
    0x9b6e1aee, 0x35f3, 0x4f4d, \
    { 0xb5, 0xbb, 0xed, 0x0e, 0xce, 0xfd, 0x85, 0x38 } \
}
struct IEventSource_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*CreateListener)(
        IEventSource *pThis,
        IEventListener * * listener
    );

    nsresult PR_COM_METHOD (*CreateAggregator)(
        IEventSource *pThis,
        PRUint32 subordinatesSize,
        IEventSource ** subordinates,
        IEventSource * * result
    );

    nsresult PR_COM_METHOD (*RegisterListener)(
        IEventSource *pThis,
        IEventListener * listener,
        PRUint32 interestingSize,
        PRUint32* interesting,
        PRBool active
    );

    nsresult PR_COM_METHOD (*UnregisterListener)(
        IEventSource *pThis,
        IEventListener * listener
    );

    nsresult PR_COM_METHOD (*FireEvent)(
        IEventSource *pThis,
        IEvent * event,
        PRInt32 timeout,
        PRBool * result
    );

    nsresult PR_COM_METHOD (*GetEvent)(
        IEventSource *pThis,
        IEventListener * listener,
        PRInt32 timeout,
        IEvent * * event
    );

    nsresult PR_COM_METHOD (*EventProcessed)(
        IEventSource *pThis,
        IEventListener * listener,
        IEvent * event
    );

};

struct IEventSource
{
    struct IEventSource_vtbl *vtbl;
};
/* End of struct IEventSource Declaration */


/* Start of struct IEventListener Declaration */
#  define IEVENTLISTENER_IID_STR "67099191-32e7-4f6c-85ee-422304c71b90"
#  define IEVENTLISTENER_IID { \
    0x67099191, 0x32e7, 0x4f6c, \
    { 0x85, 0xee, 0x42, 0x23, 0x04, 0xc7, 0x1b, 0x90 } \
}
struct IEventListener_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*HandleEvent)(
        IEventListener *pThis,
        IEvent * event
    );

};

struct IEventListener
{
    struct IEventListener_vtbl *vtbl;
};
/* End of struct IEventListener Declaration */


/* Start of struct IEvent Declaration */
#  define IEVENT_IID_STR "0ca2adba-8f30-401b-a8cd-fe31dbe839c0"
#  define IEVENT_IID { \
    0x0ca2adba, 0x8f30, 0x401b, \
    { 0xa8, 0xcd, 0xfe, 0x31, 0xdb, 0xe8, 0x39, 0xc0 } \
}
struct IEvent_vtbl
{
    struct nsISupports_vtbl nsisupports;

    nsresult PR_COM_METHOD (*GetType)(IEvent *pThis, PRUint32 *type);

    nsresult PR_COM_METHOD (*GetSource)(IEvent *pThis, IEventSource * *source);

    nsresult PR_COM_METHOD (*GetWaitable)(IEvent *pThis, PRBool *waitable);

    nsresult PR_COM_METHOD (*SetProcessed)(IEvent *pThis );

    nsresult PR_COM_METHOD (*WaitProcessed)(
        IEvent *pThis,
        PRInt32 timeout,
        PRBool * result
    );

};

struct IEvent
{
    struct IEvent_vtbl *vtbl;
};
/* End of struct IEvent Declaration */


/* Start of struct IReusableEvent Declaration */
#  define IREUSABLEEVENT_IID_STR "69bfb134-80f6-4266-8e20-16371f68fa25"
#  define IREUSABLEEVENT_IID { \
    0x69bfb134, 0x80f6, 0x4266, \
    { 0x8e, 0x20, 0x16, 0x37, 0x1f, 0x68, 0xfa, 0x25 } \
}
struct IReusableEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetGeneration)(IReusableEvent *pThis, PRUint32 *generation);

    nsresult PR_COM_METHOD (*Reuse)(IReusableEvent *pThis );

};

struct IReusableEvent
{
    struct IReusableEvent_vtbl *vtbl;
};
/* End of struct IReusableEvent Declaration */


/* Start of struct IMachineEvent Declaration */
#  define IMACHINEEVENT_IID_STR "92ed7b1a-0d96-40ed-ae46-a564d484325e"
#  define IMACHINEEVENT_IID { \
    0x92ed7b1a, 0x0d96, 0x40ed, \
    { 0xae, 0x46, 0xa5, 0x64, 0xd4, 0x84, 0x32, 0x5e } \
}
struct IMachineEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetMachineId)(IMachineEvent *pThis, PRUnichar * *machineId);

};

struct IMachineEvent
{
    struct IMachineEvent_vtbl *vtbl;
};
/* End of struct IMachineEvent Declaration */


/* Start of struct IMachineStateChangedEvent Declaration */
#  define IMACHINESTATECHANGEDEVENT_IID_STR "5748F794-48DF-438D-85EB-98FFD70D18C9"
#  define IMACHINESTATECHANGEDEVENT_IID { \
    0x5748F794, 0x48DF, 0x438D, \
    { 0x85, 0xEB, 0x98, 0xFF, 0xD7, 0x0D, 0x18, 0xC9 } \
}
struct IMachineStateChangedEvent_vtbl
{
    struct IMachineEvent_vtbl imachineevent;

    nsresult PR_COM_METHOD (*GetState)(IMachineStateChangedEvent *pThis, PRUint32 *state);

};

struct IMachineStateChangedEvent
{
    struct IMachineStateChangedEvent_vtbl *vtbl;
};
/* End of struct IMachineStateChangedEvent Declaration */


/* Start of struct IMachineDataChangedEvent Declaration */
#  define IMACHINEDATACHANGEDEVENT_IID_STR "6AA70A6C-0DCA-4810-8C5C-457B278E3D49"
#  define IMACHINEDATACHANGEDEVENT_IID { \
    0x6AA70A6C, 0x0DCA, 0x4810, \
    { 0x8C, 0x5C, 0x45, 0x7B, 0x27, 0x8E, 0x3D, 0x49 } \
}
struct IMachineDataChangedEvent_vtbl
{
    struct IMachineEvent_vtbl imachineevent;

};

struct IMachineDataChangedEvent
{
    struct IMachineDataChangedEvent_vtbl *vtbl;
};
/* End of struct IMachineDataChangedEvent Declaration */


/* Start of struct IMediumRegisteredEvent Declaration */
#  define IMEDIUMREGISTEREDEVENT_IID_STR "53fac49a-b7f1-4a5a-a4ef-a11dd9c2a458"
#  define IMEDIUMREGISTEREDEVENT_IID { \
    0x53fac49a, 0xb7f1, 0x4a5a, \
    { 0xa4, 0xef, 0xa1, 0x1d, 0xd9, 0xc2, 0xa4, 0x58 } \
}
struct IMediumRegisteredEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetMediumId)(IMediumRegisteredEvent *pThis, PRUnichar * *mediumId);

    nsresult PR_COM_METHOD (*GetMediumType)(IMediumRegisteredEvent *pThis, PRUint32 *mediumType);

    nsresult PR_COM_METHOD (*GetRegistered)(IMediumRegisteredEvent *pThis, PRBool *registered);

};

struct IMediumRegisteredEvent
{
    struct IMediumRegisteredEvent_vtbl *vtbl;
};
/* End of struct IMediumRegisteredEvent Declaration */


/* Start of struct IMachineRegisteredEvent Declaration */
#  define IMACHINEREGISTEREDEVENT_IID_STR "c354a762-3ff2-4f2e-8f09-07382ee25088"
#  define IMACHINEREGISTEREDEVENT_IID { \
    0xc354a762, 0x3ff2, 0x4f2e, \
    { 0x8f, 0x09, 0x07, 0x38, 0x2e, 0xe2, 0x50, 0x88 } \
}
struct IMachineRegisteredEvent_vtbl
{
    struct IMachineEvent_vtbl imachineevent;

    nsresult PR_COM_METHOD (*GetRegistered)(IMachineRegisteredEvent *pThis, PRBool *registered);

};

struct IMachineRegisteredEvent
{
    struct IMachineRegisteredEvent_vtbl *vtbl;
};
/* End of struct IMachineRegisteredEvent Declaration */


/* Start of struct ISessionStateChangedEvent Declaration */
#  define ISESSIONSTATECHANGEDEVENT_IID_STR "714a3eef-799a-4489-86cd-fe8e45b2ff8e"
#  define ISESSIONSTATECHANGEDEVENT_IID { \
    0x714a3eef, 0x799a, 0x4489, \
    { 0x86, 0xcd, 0xfe, 0x8e, 0x45, 0xb2, 0xff, 0x8e } \
}
struct ISessionStateChangedEvent_vtbl
{
    struct IMachineEvent_vtbl imachineevent;

    nsresult PR_COM_METHOD (*GetState)(ISessionStateChangedEvent *pThis, PRUint32 *state);

};

struct ISessionStateChangedEvent
{
    struct ISessionStateChangedEvent_vtbl *vtbl;
};
/* End of struct ISessionStateChangedEvent Declaration */


/* Start of struct IGuestPropertyChangedEvent Declaration */
#  define IGUESTPROPERTYCHANGEDEVENT_IID_STR "3f63597a-26f1-4edb-8dd2-6bddd0912368"
#  define IGUESTPROPERTYCHANGEDEVENT_IID { \
    0x3f63597a, 0x26f1, 0x4edb, \
    { 0x8d, 0xd2, 0x6b, 0xdd, 0xd0, 0x91, 0x23, 0x68 } \
}
struct IGuestPropertyChangedEvent_vtbl
{
    struct IMachineEvent_vtbl imachineevent;

    nsresult PR_COM_METHOD (*GetName)(IGuestPropertyChangedEvent *pThis, PRUnichar * *name);

    nsresult PR_COM_METHOD (*GetValue)(IGuestPropertyChangedEvent *pThis, PRUnichar * *value);

    nsresult PR_COM_METHOD (*GetFlags)(IGuestPropertyChangedEvent *pThis, PRUnichar * *flags);

};

struct IGuestPropertyChangedEvent
{
    struct IGuestPropertyChangedEvent_vtbl *vtbl;
};
/* End of struct IGuestPropertyChangedEvent Declaration */


/* Start of struct ISnapshotEvent Declaration */
#  define ISNAPSHOTEVENT_IID_STR "21637b0e-34b8-42d3-acfb-7e96daf77c22"
#  define ISNAPSHOTEVENT_IID { \
    0x21637b0e, 0x34b8, 0x42d3, \
    { 0xac, 0xfb, 0x7e, 0x96, 0xda, 0xf7, 0x7c, 0x22 } \
}
struct ISnapshotEvent_vtbl
{
    struct IMachineEvent_vtbl imachineevent;

    nsresult PR_COM_METHOD (*GetSnapshotId)(ISnapshotEvent *pThis, PRUnichar * *snapshotId);

};

struct ISnapshotEvent
{
    struct ISnapshotEvent_vtbl *vtbl;
};
/* End of struct ISnapshotEvent Declaration */


/* Start of struct ISnapshotTakenEvent Declaration */
#  define ISNAPSHOTTAKENEVENT_IID_STR "d27c0b3d-6038-422c-b45e-6d4a0503d9f1"
#  define ISNAPSHOTTAKENEVENT_IID { \
    0xd27c0b3d, 0x6038, 0x422c, \
    { 0xb4, 0x5e, 0x6d, 0x4a, 0x05, 0x03, 0xd9, 0xf1 } \
}
struct ISnapshotTakenEvent_vtbl
{
    struct ISnapshotEvent_vtbl isnapshotevent;

};

struct ISnapshotTakenEvent
{
    struct ISnapshotTakenEvent_vtbl *vtbl;
};
/* End of struct ISnapshotTakenEvent Declaration */


/* Start of struct ISnapshotDeletedEvent Declaration */
#  define ISNAPSHOTDELETEDEVENT_IID_STR "c48f3401-4a9e-43f4-b7a7-54bd285e22f4"
#  define ISNAPSHOTDELETEDEVENT_IID { \
    0xc48f3401, 0x4a9e, 0x43f4, \
    { 0xb7, 0xa7, 0x54, 0xbd, 0x28, 0x5e, 0x22, 0xf4 } \
}
struct ISnapshotDeletedEvent_vtbl
{
    struct ISnapshotEvent_vtbl isnapshotevent;

};

struct ISnapshotDeletedEvent
{
    struct ISnapshotDeletedEvent_vtbl *vtbl;
};
/* End of struct ISnapshotDeletedEvent Declaration */


/* Start of struct ISnapshotChangedEvent Declaration */
#  define ISNAPSHOTCHANGEDEVENT_IID_STR "07541941-8079-447a-a33e-47a69c7980db"
#  define ISNAPSHOTCHANGEDEVENT_IID { \
    0x07541941, 0x8079, 0x447a, \
    { 0xa3, 0x3e, 0x47, 0xa6, 0x9c, 0x79, 0x80, 0xdb } \
}
struct ISnapshotChangedEvent_vtbl
{
    struct ISnapshotEvent_vtbl isnapshotevent;

};

struct ISnapshotChangedEvent
{
    struct ISnapshotChangedEvent_vtbl *vtbl;
};
/* End of struct ISnapshotChangedEvent Declaration */


/* Start of struct IMousePointerShapeChangedEvent Declaration */
#  define IMOUSEPOINTERSHAPECHANGEDEVENT_IID_STR "a6dcf6e8-416b-4181-8c4a-45ec95177aef"
#  define IMOUSEPOINTERSHAPECHANGEDEVENT_IID { \
    0xa6dcf6e8, 0x416b, 0x4181, \
    { 0x8c, 0x4a, 0x45, 0xec, 0x95, 0x17, 0x7a, 0xef } \
}
struct IMousePointerShapeChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetVisible)(IMousePointerShapeChangedEvent *pThis, PRBool *visible);

    nsresult PR_COM_METHOD (*GetAlpha)(IMousePointerShapeChangedEvent *pThis, PRBool *alpha);

    nsresult PR_COM_METHOD (*GetXhot)(IMousePointerShapeChangedEvent *pThis, PRUint32 *xhot);

    nsresult PR_COM_METHOD (*GetYhot)(IMousePointerShapeChangedEvent *pThis, PRUint32 *yhot);

    nsresult PR_COM_METHOD (*GetWidth)(IMousePointerShapeChangedEvent *pThis, PRUint32 *width);

    nsresult PR_COM_METHOD (*GetHeight)(IMousePointerShapeChangedEvent *pThis, PRUint32 *height);

    nsresult PR_COM_METHOD (*GetShape)(IMousePointerShapeChangedEvent *pThis, PRUint32 *shapeSize, PRUint8 **shape);

};

struct IMousePointerShapeChangedEvent
{
    struct IMousePointerShapeChangedEvent_vtbl *vtbl;
};
/* End of struct IMousePointerShapeChangedEvent Declaration */


/* Start of struct IMouseCapabilityChangedEvent Declaration */
#  define IMOUSECAPABILITYCHANGEDEVENT_IID_STR "d633ad48-820c-4207-b46c-6bd3596640d5"
#  define IMOUSECAPABILITYCHANGEDEVENT_IID { \
    0xd633ad48, 0x820c, 0x4207, \
    { 0xb4, 0x6c, 0x6b, 0xd3, 0x59, 0x66, 0x40, 0xd5 } \
}
struct IMouseCapabilityChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetSupportsAbsolute)(IMouseCapabilityChangedEvent *pThis, PRBool *supportsAbsolute);

    nsresult PR_COM_METHOD (*GetSupportsRelative)(IMouseCapabilityChangedEvent *pThis, PRBool *supportsRelative);

    nsresult PR_COM_METHOD (*GetNeedsHostCursor)(IMouseCapabilityChangedEvent *pThis, PRBool *needsHostCursor);

};

struct IMouseCapabilityChangedEvent
{
    struct IMouseCapabilityChangedEvent_vtbl *vtbl;
};
/* End of struct IMouseCapabilityChangedEvent Declaration */


/* Start of struct IKeyboardLedsChangedEvent Declaration */
#  define IKEYBOARDLEDSCHANGEDEVENT_IID_STR "6DDEF35E-4737-457B-99FC-BC52C851A44F"
#  define IKEYBOARDLEDSCHANGEDEVENT_IID { \
    0x6DDEF35E, 0x4737, 0x457B, \
    { 0x99, 0xFC, 0xBC, 0x52, 0xC8, 0x51, 0xA4, 0x4F } \
}
struct IKeyboardLedsChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetNumLock)(IKeyboardLedsChangedEvent *pThis, PRBool *numLock);

    nsresult PR_COM_METHOD (*GetCapsLock)(IKeyboardLedsChangedEvent *pThis, PRBool *capsLock);

    nsresult PR_COM_METHOD (*GetScrollLock)(IKeyboardLedsChangedEvent *pThis, PRBool *scrollLock);

};

struct IKeyboardLedsChangedEvent
{
    struct IKeyboardLedsChangedEvent_vtbl *vtbl;
};
/* End of struct IKeyboardLedsChangedEvent Declaration */


/* Start of struct IStateChangedEvent Declaration */
#  define ISTATECHANGEDEVENT_IID_STR "4376693C-CF37-453B-9289-3B0F521CAF27"
#  define ISTATECHANGEDEVENT_IID { \
    0x4376693C, 0xCF37, 0x453B, \
    { 0x92, 0x89, 0x3B, 0x0F, 0x52, 0x1C, 0xAF, 0x27 } \
}
struct IStateChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetState)(IStateChangedEvent *pThis, PRUint32 *state);

};

struct IStateChangedEvent
{
    struct IStateChangedEvent_vtbl *vtbl;
};
/* End of struct IStateChangedEvent Declaration */


/* Start of struct IAdditionsStateChangedEvent Declaration */
#  define IADDITIONSSTATECHANGEDEVENT_IID_STR "D70F7915-DA7C-44C8-A7AC-9F173490446A"
#  define IADDITIONSSTATECHANGEDEVENT_IID { \
    0xD70F7915, 0xDA7C, 0x44C8, \
    { 0xA7, 0xAC, 0x9F, 0x17, 0x34, 0x90, 0x44, 0x6A } \
}
struct IAdditionsStateChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

};

struct IAdditionsStateChangedEvent
{
    struct IAdditionsStateChangedEvent_vtbl *vtbl;
};
/* End of struct IAdditionsStateChangedEvent Declaration */


/* Start of struct INetworkAdapterChangedEvent Declaration */
#  define INETWORKADAPTERCHANGEDEVENT_IID_STR "08889892-1EC6-4883-801D-77F56CFD0103"
#  define INETWORKADAPTERCHANGEDEVENT_IID { \
    0x08889892, 0x1EC6, 0x4883, \
    { 0x80, 0x1D, 0x77, 0xF5, 0x6C, 0xFD, 0x01, 0x03 } \
}
struct INetworkAdapterChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetNetworkAdapter)(INetworkAdapterChangedEvent *pThis, INetworkAdapter * *networkAdapter);

};

struct INetworkAdapterChangedEvent
{
    struct INetworkAdapterChangedEvent_vtbl *vtbl;
};
/* End of struct INetworkAdapterChangedEvent Declaration */


/* Start of struct ISerialPortChangedEvent Declaration */
#  define ISERIALPORTCHANGEDEVENT_IID_STR "3BA329DC-659C-488B-835C-4ECA7AE71C6C"
#  define ISERIALPORTCHANGEDEVENT_IID { \
    0x3BA329DC, 0x659C, 0x488B, \
    { 0x83, 0x5C, 0x4E, 0xCA, 0x7A, 0xE7, 0x1C, 0x6C } \
}
struct ISerialPortChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetSerialPort)(ISerialPortChangedEvent *pThis, ISerialPort * *serialPort);

};

struct ISerialPortChangedEvent
{
    struct ISerialPortChangedEvent_vtbl *vtbl;
};
/* End of struct ISerialPortChangedEvent Declaration */


/* Start of struct IParallelPortChangedEvent Declaration */
#  define IPARALLELPORTCHANGEDEVENT_IID_STR "813C99FC-9849-4F47-813E-24A75DC85615"
#  define IPARALLELPORTCHANGEDEVENT_IID { \
    0x813C99FC, 0x9849, 0x4F47, \
    { 0x81, 0x3E, 0x24, 0xA7, 0x5D, 0xC8, 0x56, 0x15 } \
}
struct IParallelPortChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetParallelPort)(IParallelPortChangedEvent *pThis, IParallelPort * *parallelPort);

};

struct IParallelPortChangedEvent
{
    struct IParallelPortChangedEvent_vtbl *vtbl;
};
/* End of struct IParallelPortChangedEvent Declaration */


/* Start of struct IStorageControllerChangedEvent Declaration */
#  define ISTORAGECONTROLLERCHANGEDEVENT_IID_STR "715212BF-DA59-426E-8230-3831FAA52C56"
#  define ISTORAGECONTROLLERCHANGEDEVENT_IID { \
    0x715212BF, 0xDA59, 0x426E, \
    { 0x82, 0x30, 0x38, 0x31, 0xFA, 0xA5, 0x2C, 0x56 } \
}
struct IStorageControllerChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

};

struct IStorageControllerChangedEvent
{
    struct IStorageControllerChangedEvent_vtbl *vtbl;
};
/* End of struct IStorageControllerChangedEvent Declaration */


/* Start of struct IMediumChangedEvent Declaration */
#  define IMEDIUMCHANGEDEVENT_IID_STR "0FE2DA40-5637-472A-9736-72019EABD7DE"
#  define IMEDIUMCHANGEDEVENT_IID { \
    0x0FE2DA40, 0x5637, 0x472A, \
    { 0x97, 0x36, 0x72, 0x01, 0x9E, 0xAB, 0xD7, 0xDE } \
}
struct IMediumChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetMediumAttachment)(IMediumChangedEvent *pThis, IMediumAttachment * *mediumAttachment);

};

struct IMediumChangedEvent
{
    struct IMediumChangedEvent_vtbl *vtbl;
};
/* End of struct IMediumChangedEvent Declaration */


/* Start of struct ICPUChangedEvent Declaration */
#  define ICPUCHANGEDEVENT_IID_STR "D0F0BECC-EE17-4D17-A8CC-383B0EB55E9D"
#  define ICPUCHANGEDEVENT_IID { \
    0xD0F0BECC, 0xEE17, 0x4D17, \
    { 0xA8, 0xCC, 0x38, 0x3B, 0x0E, 0xB5, 0x5E, 0x9D } \
}
struct ICPUChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetCpu)(ICPUChangedEvent *pThis, PRUint32 *cpu);

    nsresult PR_COM_METHOD (*GetAdd)(ICPUChangedEvent *pThis, PRBool *add);

};

struct ICPUChangedEvent
{
    struct ICPUChangedEvent_vtbl *vtbl;
};
/* End of struct ICPUChangedEvent Declaration */


/* Start of struct ICPUExecutionCapChangedEvent Declaration */
#  define ICPUEXECUTIONCAPCHANGEDEVENT_IID_STR "dfa7e4f5-b4a4-44ce-85a8-127ac5eb59dc"
#  define ICPUEXECUTIONCAPCHANGEDEVENT_IID { \
    0xdfa7e4f5, 0xb4a4, 0x44ce, \
    { 0x85, 0xa8, 0x12, 0x7a, 0xc5, 0xeb, 0x59, 0xdc } \
}
struct ICPUExecutionCapChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetExecutionCap)(ICPUExecutionCapChangedEvent *pThis, PRUint32 *executionCap);

};

struct ICPUExecutionCapChangedEvent
{
    struct ICPUExecutionCapChangedEvent_vtbl *vtbl;
};
/* End of struct ICPUExecutionCapChangedEvent Declaration */


/* Start of struct IGuestKeyboardEvent Declaration */
#  define IGUESTKEYBOARDEVENT_IID_STR "88394258-7006-40d4-b339-472ee3801844"
#  define IGUESTKEYBOARDEVENT_IID { \
    0x88394258, 0x7006, 0x40d4, \
    { 0xb3, 0x39, 0x47, 0x2e, 0xe3, 0x80, 0x18, 0x44 } \
}
struct IGuestKeyboardEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetScancodes)(IGuestKeyboardEvent *pThis, PRUint32 *scancodesSize, PRInt32 **scancodes);

};

struct IGuestKeyboardEvent
{
    struct IGuestKeyboardEvent_vtbl *vtbl;
};
/* End of struct IGuestKeyboardEvent Declaration */


/* Start of struct IGuestMouseEvent Declaration */
#  define IGUESTMOUSEEVENT_IID_STR "1f85d35c-c524-40ff-8e98-307000df0992"
#  define IGUESTMOUSEEVENT_IID { \
    0x1f85d35c, 0xc524, 0x40ff, \
    { 0x8e, 0x98, 0x30, 0x70, 0x00, 0xdf, 0x09, 0x92 } \
}
struct IGuestMouseEvent_vtbl
{
    struct IReusableEvent_vtbl ireusableevent;

    nsresult PR_COM_METHOD (*GetAbsolute)(IGuestMouseEvent *pThis, PRBool *absolute);

    nsresult PR_COM_METHOD (*GetX)(IGuestMouseEvent *pThis, PRInt32 *x);

    nsresult PR_COM_METHOD (*GetY)(IGuestMouseEvent *pThis, PRInt32 *y);

    nsresult PR_COM_METHOD (*GetZ)(IGuestMouseEvent *pThis, PRInt32 *z);

    nsresult PR_COM_METHOD (*GetW)(IGuestMouseEvent *pThis, PRInt32 *w);

    nsresult PR_COM_METHOD (*GetButtons)(IGuestMouseEvent *pThis, PRInt32 *buttons);

};

struct IGuestMouseEvent
{
    struct IGuestMouseEvent_vtbl *vtbl;
};
/* End of struct IGuestMouseEvent Declaration */


/* Start of struct IVRDEServerChangedEvent Declaration */
#  define IVRDESERVERCHANGEDEVENT_IID_STR "a06fd66a-3188-4c8c-8756-1395e8cb691c"
#  define IVRDESERVERCHANGEDEVENT_IID { \
    0xa06fd66a, 0x3188, 0x4c8c, \
    { 0x87, 0x56, 0x13, 0x95, 0xe8, 0xcb, 0x69, 0x1c } \
}
struct IVRDEServerChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

};

struct IVRDEServerChangedEvent
{
    struct IVRDEServerChangedEvent_vtbl *vtbl;
};
/* End of struct IVRDEServerChangedEvent Declaration */


/* Start of struct IVRDEServerInfoChangedEvent Declaration */
#  define IVRDESERVERINFOCHANGEDEVENT_IID_STR "dd6a1080-e1b7-4339-a549-f0878115596e"
#  define IVRDESERVERINFOCHANGEDEVENT_IID { \
    0xdd6a1080, 0xe1b7, 0x4339, \
    { 0xa5, 0x49, 0xf0, 0x87, 0x81, 0x15, 0x59, 0x6e } \
}
struct IVRDEServerInfoChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

};

struct IVRDEServerInfoChangedEvent
{
    struct IVRDEServerInfoChangedEvent_vtbl *vtbl;
};
/* End of struct IVRDEServerInfoChangedEvent Declaration */


/* Start of struct IUSBControllerChangedEvent Declaration */
#  define IUSBCONTROLLERCHANGEDEVENT_IID_STR "93BADC0C-61D9-4940-A084-E6BB29AF3D83"
#  define IUSBCONTROLLERCHANGEDEVENT_IID { \
    0x93BADC0C, 0x61D9, 0x4940, \
    { 0xA0, 0x84, 0xE6, 0xBB, 0x29, 0xAF, 0x3D, 0x83 } \
}
struct IUSBControllerChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

};

struct IUSBControllerChangedEvent
{
    struct IUSBControllerChangedEvent_vtbl *vtbl;
};
/* End of struct IUSBControllerChangedEvent Declaration */


/* Start of struct IUSBDeviceStateChangedEvent Declaration */
#  define IUSBDEVICESTATECHANGEDEVENT_IID_STR "806da61b-6679-422a-b629-51b06b0c6d93"
#  define IUSBDEVICESTATECHANGEDEVENT_IID { \
    0x806da61b, 0x6679, 0x422a, \
    { 0xb6, 0x29, 0x51, 0xb0, 0x6b, 0x0c, 0x6d, 0x93 } \
}
struct IUSBDeviceStateChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetDevice)(IUSBDeviceStateChangedEvent *pThis, IUSBDevice * *device);

    nsresult PR_COM_METHOD (*GetAttached)(IUSBDeviceStateChangedEvent *pThis, PRBool *attached);

    nsresult PR_COM_METHOD (*GetError)(IUSBDeviceStateChangedEvent *pThis, IVirtualBoxErrorInfo * *error);

};

struct IUSBDeviceStateChangedEvent
{
    struct IUSBDeviceStateChangedEvent_vtbl *vtbl;
};
/* End of struct IUSBDeviceStateChangedEvent Declaration */


/* Start of struct ISharedFolderChangedEvent Declaration */
#  define ISHAREDFOLDERCHANGEDEVENT_IID_STR "B66349B5-3534-4239-B2DE-8E1535D94C0B"
#  define ISHAREDFOLDERCHANGEDEVENT_IID { \
    0xB66349B5, 0x3534, 0x4239, \
    { 0xB2, 0xDE, 0x8E, 0x15, 0x35, 0xD9, 0x4C, 0x0B } \
}
struct ISharedFolderChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetScope)(ISharedFolderChangedEvent *pThis, PRUint32 *scope);

};

struct ISharedFolderChangedEvent
{
    struct ISharedFolderChangedEvent_vtbl *vtbl;
};
/* End of struct ISharedFolderChangedEvent Declaration */


/* Start of struct IRuntimeErrorEvent Declaration */
#  define IRUNTIMEERROREVENT_IID_STR "883DD18B-0721-4CDE-867C-1A82ABAF914C"
#  define IRUNTIMEERROREVENT_IID { \
    0x883DD18B, 0x0721, 0x4CDE, \
    { 0x86, 0x7C, 0x1A, 0x82, 0xAB, 0xAF, 0x91, 0x4C } \
}
struct IRuntimeErrorEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetFatal)(IRuntimeErrorEvent *pThis, PRBool *fatal);

    nsresult PR_COM_METHOD (*GetId)(IRuntimeErrorEvent *pThis, PRUnichar * *id);

    nsresult PR_COM_METHOD (*GetMessage)(IRuntimeErrorEvent *pThis, PRUnichar * *message);

};

struct IRuntimeErrorEvent
{
    struct IRuntimeErrorEvent_vtbl *vtbl;
};
/* End of struct IRuntimeErrorEvent Declaration */


/* Start of struct IEventSourceChangedEvent Declaration */
#  define IEVENTSOURCECHANGEDEVENT_IID_STR "e7932cb8-f6d4-4ab6-9cbf-558eb8959a6a"
#  define IEVENTSOURCECHANGEDEVENT_IID { \
    0xe7932cb8, 0xf6d4, 0x4ab6, \
    { 0x9c, 0xbf, 0x55, 0x8e, 0xb8, 0x95, 0x9a, 0x6a } \
}
struct IEventSourceChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetListener)(IEventSourceChangedEvent *pThis, IEventListener * *listener);

    nsresult PR_COM_METHOD (*GetAdd)(IEventSourceChangedEvent *pThis, PRBool *add);

};

struct IEventSourceChangedEvent
{
    struct IEventSourceChangedEvent_vtbl *vtbl;
};
/* End of struct IEventSourceChangedEvent Declaration */


/* Start of struct IExtraDataChangedEvent Declaration */
#  define IEXTRADATACHANGEDEVENT_IID_STR "024F00CE-6E0B-492A-A8D0-968472A94DC7"
#  define IEXTRADATACHANGEDEVENT_IID { \
    0x024F00CE, 0x6E0B, 0x492A, \
    { 0xA8, 0xD0, 0x96, 0x84, 0x72, 0xA9, 0x4D, 0xC7 } \
}
struct IExtraDataChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetMachineId)(IExtraDataChangedEvent *pThis, PRUnichar * *machineId);

    nsresult PR_COM_METHOD (*GetKey)(IExtraDataChangedEvent *pThis, PRUnichar * *key);

    nsresult PR_COM_METHOD (*GetValue)(IExtraDataChangedEvent *pThis, PRUnichar * *value);

};

struct IExtraDataChangedEvent
{
    struct IExtraDataChangedEvent_vtbl *vtbl;
};
/* End of struct IExtraDataChangedEvent Declaration */


/* Start of struct IVetoEvent Declaration */
#  define IVETOEVENT_IID_STR "9a1a4130-69fe-472f-ac10-c6fa25d75007"
#  define IVETOEVENT_IID { \
    0x9a1a4130, 0x69fe, 0x472f, \
    { 0xac, 0x10, 0xc6, 0xfa, 0x25, 0xd7, 0x50, 0x07 } \
}
struct IVetoEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*AddVeto)(
        IVetoEvent *pThis,
        PRUnichar * reason
    );

    nsresult PR_COM_METHOD (*IsVetoed)(
        IVetoEvent *pThis,
        PRBool * result
    );

    nsresult PR_COM_METHOD (*GetVetos)(
        IVetoEvent *pThis,
        PRUint32 *resultSize,
        PRUnichar *** result
    );

};

struct IVetoEvent
{
    struct IVetoEvent_vtbl *vtbl;
};
/* End of struct IVetoEvent Declaration */


/* Start of struct IExtraDataCanChangeEvent Declaration */
#  define IEXTRADATACANCHANGEEVENT_IID_STR "245d88bd-800a-40f8-87a6-170d02249a55"
#  define IEXTRADATACANCHANGEEVENT_IID { \
    0x245d88bd, 0x800a, 0x40f8, \
    { 0x87, 0xa6, 0x17, 0x0d, 0x02, 0x24, 0x9a, 0x55 } \
}
struct IExtraDataCanChangeEvent_vtbl
{
    struct IVetoEvent_vtbl ivetoevent;

    nsresult PR_COM_METHOD (*GetMachineId)(IExtraDataCanChangeEvent *pThis, PRUnichar * *machineId);

    nsresult PR_COM_METHOD (*GetKey)(IExtraDataCanChangeEvent *pThis, PRUnichar * *key);

    nsresult PR_COM_METHOD (*GetValue)(IExtraDataCanChangeEvent *pThis, PRUnichar * *value);

};

struct IExtraDataCanChangeEvent
{
    struct IExtraDataCanChangeEvent_vtbl *vtbl;
};
/* End of struct IExtraDataCanChangeEvent Declaration */


/* Start of struct ICanShowWindowEvent Declaration */
#  define ICANSHOWWINDOWEVENT_IID_STR "adf292b0-92c9-4a77-9d35-e058b39fe0b9"
#  define ICANSHOWWINDOWEVENT_IID { \
    0xadf292b0, 0x92c9, 0x4a77, \
    { 0x9d, 0x35, 0xe0, 0x58, 0xb3, 0x9f, 0xe0, 0xb9 } \
}
struct ICanShowWindowEvent_vtbl
{
    struct IVetoEvent_vtbl ivetoevent;

};

struct ICanShowWindowEvent
{
    struct ICanShowWindowEvent_vtbl *vtbl;
};
/* End of struct ICanShowWindowEvent Declaration */


/* Start of struct IShowWindowEvent Declaration */
#  define ISHOWWINDOWEVENT_IID_STR "B0A0904D-2F05-4D28-855F-488F96BAD2B2"
#  define ISHOWWINDOWEVENT_IID { \
    0xB0A0904D, 0x2F05, 0x4D28, \
    { 0x85, 0x5F, 0x48, 0x8F, 0x96, 0xBA, 0xD2, 0xB2 } \
}
struct IShowWindowEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetWinId)(IShowWindowEvent *pThis, PRInt64 *winId);
    nsresult PR_COM_METHOD (*SetWinId)(IShowWindowEvent *pThis, PRInt64 winId);

};

struct IShowWindowEvent
{
    struct IShowWindowEvent_vtbl *vtbl;
};
/* End of struct IShowWindowEvent Declaration */


/* Start of struct INATRedirectEvent Declaration */
#  define INATREDIRECTEVENT_IID_STR "57DE97D7-3CBB-42A0-888F-610D5832D16B"
#  define INATREDIRECTEVENT_IID { \
    0x57DE97D7, 0x3CBB, 0x42A0, \
    { 0x88, 0x8F, 0x61, 0x0D, 0x58, 0x32, 0xD1, 0x6B } \
}
struct INATRedirectEvent_vtbl
{
    struct IMachineEvent_vtbl imachineevent;

    nsresult PR_COM_METHOD (*GetSlot)(INATRedirectEvent *pThis, PRUint32 *slot);

    nsresult PR_COM_METHOD (*GetRemove)(INATRedirectEvent *pThis, PRBool *remove);

    nsresult PR_COM_METHOD (*GetName)(INATRedirectEvent *pThis, PRUnichar * *name);

    nsresult PR_COM_METHOD (*GetProto)(INATRedirectEvent *pThis, PRUint32 *proto);

    nsresult PR_COM_METHOD (*GetHostIp)(INATRedirectEvent *pThis, PRUnichar * *hostIp);

    nsresult PR_COM_METHOD (*GetHostPort)(INATRedirectEvent *pThis, PRInt32 *hostPort);

    nsresult PR_COM_METHOD (*GetGuestIp)(INATRedirectEvent *pThis, PRUnichar * *guestIp);

    nsresult PR_COM_METHOD (*GetGuestPort)(INATRedirectEvent *pThis, PRInt32 *guestPort);

};

struct INATRedirectEvent
{
    struct INATRedirectEvent_vtbl *vtbl;
};
/* End of struct INATRedirectEvent Declaration */


/* Start of struct IHostPciDevicePlugEvent Declaration */
#  define IHOSTPCIDEVICEPLUGEVENT_IID_STR "EDD4782B-DB74-43A0-B724-2BAA36F039CC"
#  define IHOSTPCIDEVICEPLUGEVENT_IID { \
    0xEDD4782B, 0xDB74, 0x43A0, \
    { 0xB7, 0x24, 0x2B, 0xAA, 0x36, 0xF0, 0x39, 0xCC } \
}
struct IHostPciDevicePlugEvent_vtbl
{
    struct IMachineEvent_vtbl imachineevent;

    nsresult PR_COM_METHOD (*GetPlugged)(IHostPciDevicePlugEvent *pThis, PRBool *plugged);

    nsresult PR_COM_METHOD (*GetSuccess)(IHostPciDevicePlugEvent *pThis, PRBool *success);

    nsresult PR_COM_METHOD (*GetAttachment)(IHostPciDevicePlugEvent *pThis, IPciDeviceAttachment * *attachment);

    nsresult PR_COM_METHOD (*GetEventContext)(IHostPciDevicePlugEvent *pThis, IEventContext * *eventContext);

    nsresult PR_COM_METHOD (*GetMessage)(IHostPciDevicePlugEvent *pThis, PRUnichar * *message);

};

struct IHostPciDevicePlugEvent
{
    struct IHostPciDevicePlugEvent_vtbl *vtbl;
};
/* End of struct IHostPciDevicePlugEvent Declaration */


/* Start of struct IVBoxSVCAvailabilityChangedEvent Declaration */
#  define IVBOXSVCAVAILABILITYCHANGEDEVENT_IID_STR "97c78fcd-d4fc-485f-8613-5af88bfcfcdc"
#  define IVBOXSVCAVAILABILITYCHANGEDEVENT_IID { \
    0x97c78fcd, 0xd4fc, 0x485f, \
    { 0x86, 0x13, 0x5a, 0xf8, 0x8b, 0xfc, 0xfc, 0xdc } \
}
struct IVBoxSVCAvailabilityChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetAvailable)(IVBoxSVCAvailabilityChangedEvent *pThis, PRBool *available);

};

struct IVBoxSVCAvailabilityChangedEvent
{
    struct IVBoxSVCAvailabilityChangedEvent_vtbl *vtbl;
};
/* End of struct IVBoxSVCAvailabilityChangedEvent Declaration */


/* Start of struct IBandwidthGroupChangedEvent Declaration */
#  define IBANDWIDTHGROUPCHANGEDEVENT_IID_STR "334df94a-7556-4cbc-8c04-043096b02d82"
#  define IBANDWIDTHGROUPCHANGEDEVENT_IID { \
    0x334df94a, 0x7556, 0x4cbc, \
    { 0x8c, 0x04, 0x04, 0x30, 0x96, 0xb0, 0x2d, 0x82 } \
}
struct IBandwidthGroupChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetBandwidthGroup)(IBandwidthGroupChangedEvent *pThis, IBandwidthGroup * *bandwidthGroup);

};

struct IBandwidthGroupChangedEvent
{
    struct IBandwidthGroupChangedEvent_vtbl *vtbl;
};
/* End of struct IBandwidthGroupChangedEvent Declaration */


/* Start of struct IGuestMonitorChangedEvent Declaration */
#  define IGUESTMONITORCHANGEDEVENT_IID_STR "0f7b8a22-c71f-4a36-8e5f-a77d01d76090"
#  define IGUESTMONITORCHANGEDEVENT_IID { \
    0x0f7b8a22, 0xc71f, 0x4a36, \
    { 0x8e, 0x5f, 0xa7, 0x7d, 0x01, 0xd7, 0x60, 0x90 } \
}
struct IGuestMonitorChangedEvent_vtbl
{
    struct IEvent_vtbl ievent;

    nsresult PR_COM_METHOD (*GetChangeType)(IGuestMonitorChangedEvent *pThis, PRUint32 *changeType);

    nsresult PR_COM_METHOD (*GetScreenId)(IGuestMonitorChangedEvent *pThis, PRUint32 *screenId);

    nsresult PR_COM_METHOD (*GetOriginX)(IGuestMonitorChangedEvent *pThis, PRUint32 *originX);

    nsresult PR_COM_METHOD (*GetOriginY)(IGuestMonitorChangedEvent *pThis, PRUint32 *originY);

    nsresult PR_COM_METHOD (*GetWidth)(IGuestMonitorChangedEvent *pThis, PRUint32 *width);

    nsresult PR_COM_METHOD (*GetHeight)(IGuestMonitorChangedEvent *pThis, PRUint32 *height);

};

struct IGuestMonitorChangedEvent
{
    struct IGuestMonitorChangedEvent_vtbl *vtbl;
};
/* End of struct IGuestMonitorChangedEvent Declaration */



#  define NS_VIRTUALBOX_CID { \
    0xB1A7A4F2, 0x47B9, 0x4A1E, \
    { 0x82, 0xB2, 0x07, 0xCC, 0xD5, 0x32, 0x3C, 0x3F } \
}
#  define NS_VIRTUALBOX_CONTRACTID "@virtualbox.org/VirtualBox;1"
/* for compatibility with Win32 */
#  define CLSID_VirtualBox (nsCID) NS_VIRTUALBOX_CID



#  define NS_VIRTUALBOXCLIENT_CID { \
    0xdd3fc71d, 0x26c0, 0x4fe1, \
    { 0xbf, 0x6f, 0x67, 0xf6, 0x33, 0x26, 0x5b, 0xba } \
}
#  define NS_VIRTUALBOXCLIENT_CONTRACTID "@virtualbox.org/VirtualBoxClient;1"
/* for compatibility with Win32 */
#  define CLSID_VirtualBoxClient (nsCID) NS_VIRTUALBOXCLIENT_CID



#  define NS_SESSION_CID { \
    0x3C02F46D, 0xC9D2, 0x4F11, \
    { 0xA3, 0x84, 0x53, 0xF0, 0xCF, 0x91, 0x72, 0x14 } \
}
#  define NS_SESSION_CONTRACTID "@virtualbox.org/Session;1"
/* for compatibility with Win32 */
#  define CLSID_Session (nsCID) NS_SESSION_CID



# endif /* !__cplusplus */

# ifdef IN_VBOXXPCOMC
#  define VBOXXPCOMC_DECL(type)  PR_EXPORT(type)
# else
#  define VBOXXPCOMC_DECL(type)  PR_IMPORT(type)
# endif

# ifdef __cplusplus
extern "C" {
# endif


/**
 * Function table for dynamic linking.
 * Use VBoxGetFunctions() to obtain the pointer to it.
 */
typedef struct VBOXXPCOMC
{
    /** The size of the structure. */
    unsigned cb;
    /** The structure version. */
    unsigned uVersion;

    unsigned int (*pfnGetVersion)(void);

    void  (*pfnComInitialize)(const char *pszVirtualBoxIID,
                              IVirtualBox **ppVirtualBox,
                              const char *pszSessionIID,
                              ISession **ppSession);
    void (*pfnComUninitialize)(void);

    void  (*pfnComUnallocMem)(void *pv);
    void  (*pfnUtf16Free)(PRUnichar *pwszString);
    void  (*pfnUtf8Free)(char *pszString);

    int   (*pfnUtf16ToUtf8)(const PRUnichar *pwszString, char **ppszString);
    int   (*pfnUtf8ToUtf16)(const char *pszString, PRUnichar **ppwszString);

    void  (*pfnGetEventQueue)(nsIEventQueue **eventQueue);

    /** Tail version, same as uVersion. */
    unsigned uEndVersion;
} VBOXXPCOMC;
/** Pointer to a const VBoxXPCOMC function table. */
typedef VBOXXPCOMC const *PCVBOXXPCOM;

/** The current interface version.
 * For use with VBoxGetXPCOMCFunctions and to be found in
 * VBOXXPCOMC::uVersion. */
# define VBOX_XPCOMC_VERSION     0x00020000U

VBOXXPCOMC_DECL(PCVBOXXPCOM) VBoxGetXPCOMCFunctions(unsigned uVersion);
/** Typedef for VBoxGetXPCOMCFunctions. */
typedef PCVBOXXPCOM (*PFNVBOXGETXPCOMCFUNCTIONS)(unsigned uVersion);

/** The symbol name of VBoxGetXPCOMCFunctions. */
# if defined(__OS2__)
#  define VBOX_GET_XPCOMC_FUNCTIONS_SYMBOL_NAME   "_VBoxGetXPCOMCFunctions"
# else
#  define VBOX_GET_XPCOMC_FUNCTIONS_SYMBOL_NAME   "VBoxGetXPCOMCFunctions"
# endif


# ifdef __cplusplus
}
# endif

#endif /* !___VirtualBox_CXPCOM_h */
