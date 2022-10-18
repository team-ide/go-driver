#ifndef _OBJ_HEADER__INCLUDE__
#define _OBJ_HEADER__INCLUDE__

/************************************************************************/
/**
 * @file
 *      obj.h
 * @brief
 *      Object功能相关定义头文件，公开   
 */                                                                     
/************************************************************************/

#include "acitype.h"

/*---------------------------------------------------------------------------*/
/*                    PUBLIC TYPES, CONSTANTS AND MACROS                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                  GENERAL OBJECT TYPES, CONSTANTS, MACROS                  */
/*---------------------------------------------------------------------------*/

/*------------------------- OBJECT REFERENCE (REF) --------------------------*/

/*---------------------------------------------------------------------------*/
/*                               TYPE MANAGER                                */
/*---------------------------------------------------------------------------*/

/*------------------------------ TYPE CODE ----------------------------------*/

/*
 * Type manager typecodes
 *
 * These are typecodes designed to be used with the type manager;
 * they also include longer, more readable versions of existing SQLT names.
 * Those types that are directly related to existing SQLT types are #define'd
 * to their SQLT equivalents.
 *
 * The type manager typecodes are designed to be useable for all ACI calls.
 * They are in the range from 192 to 320 for typecodes, so as not to conflict
 * with existing ACI SQLT typecodes (see ocidfn.h).
 */

#define ACI_TYPECODE_REF         SQLT_REF        /* SQL/OTS OBJECT REFERENCE */
#define ACI_TYPECODE_DATE        SQLT_DAT              /* SQL DATE  OTS DATE */
#define ACI_TYPECODE_SIGNED8     27      /* SQL SIGNED INTEGER(8)  OTS SINT8 */
#define ACI_TYPECODE_SIGNED16    28    /* SQL SIGNED INTEGER(16)  OTS SINT16 */
#define ACI_TYPECODE_SIGNED32    29    /* SQL SIGNED INTEGER(32)  OTS SINT32 */
#define ACI_TYPECODE_REAL        21                /* SQL REAL  OTS SQL_REAL */
#define ACI_TYPECODE_DOUBLE      22  /* SQL DOUBLE PRECISION  OTS SQL_DOUBLE */
#define ACI_TYPECODE_BFLOAT      SQLT_IBFLOAT       /* Binary float */ 
#define ACI_TYPECODE_BDOUBLE     SQLT_IBDOUBLE  /* Binary double */
#define ACI_TYPECODE_FLOAT       SQLT_FLT      /* SQL FLOAT(P)  OTS FLOAT(P) */
#define ACI_TYPECODE_NUMBER      SQLT_NUM/* SQL NUMBER(P S)  OTS NUMBER(P S) */
#define ACI_TYPECODE_DECIMAL     SQLT_PDN
 /* SQL DECIMAL(P S)  OTS DECIMAL(P S) */
#define ACI_TYPECODE_UNSIGNED8   SQLT_BIN
                                       /* SQL UNSIGNED INTEGER(8)  OTS UINT8 */
#define ACI_TYPECODE_UNSIGNED16  25  /* SQL UNSIGNED INTEGER(16)  OTS UINT16 */
#define ACI_TYPECODE_UNSIGNED32  26  /* SQL UNSIGNED INTEGER(32)  OTS UINT32 */
#define ACI_TYPECODE_OCTET       245                   /* SQL ???  OTS OCTET */
#define ACI_TYPECODE_SMALLINT    246           /* SQL SMALLINT  OTS SMALLINT */
#define ACI_TYPECODE_INTEGER     SQLT_INT        /* SQL INTEGER  OTS INTEGER */
#define ACI_TYPECODE_RAW         SQLT_LVB          /* SQL RAW(N)  OTS RAW(N) */
#define ACI_TYPECODE_PTR         32              /* SQL POINTER  OTS POINTER */
#define ACI_TYPECODE_VARCHAR2    SQLT_VCS
                                     /* SQL VARCHAR2(N)  OTS SQL_VARCHAR2(N) */
#define ACI_TYPECODE_CHAR        SQLT_AFC    /* SQL CHAR(N)  OTS SQL_CHAR(N) */
#define ACI_TYPECODE_VARCHAR     SQLT_CHR
                                       /* SQL VARCHAR(N)  OTS SQL_VARCHAR(N) */
#define ACI_TYPECODE_MLSLABEL    SQLT_LAB                    /* OTS MLSLABEL */
#define ACI_TYPECODE_VARRAY      247         /* SQL VARRAY  OTS PAGED VARRAY */
#define ACI_TYPECODE_TABLE       248              /* SQL TABLE  OTS MULTISET */
#define ACI_TYPECODE_OBJECT      SQLT_NTY       /* SQL/OTS NAMED OBJECT TYPE */
#define ACI_TYPECODE_OPAQUE       58                /*  SQL/OTS Opaque Types */
#define ACI_TYPECODE_NAMEDCOLLECTION  SQLT_NCO
                                            /* SQL/OTS NAMED COLLECTION TYPE */
#define ACI_TYPECODE_BLOB        SQLT_BLOB    /* SQL/OTS BINARY LARGE OBJECT */
#define ACI_TYPECODE_BFILE       SQLT_BFILE    /* SQL/OTS BINARY FILE OBJECT */
#define ACI_TYPECODE_CLOB        SQLT_CLOB /* SQL/OTS CHARACTER LARGE OBJECT */
#define ACI_TYPECODE_CFILE       SQLT_CFILE /* SQL/OTS CHARACTER FILE OBJECT */

/* the following are ANSI datetime datatypes added in 8.1 */
#define ACI_TYPECODE_TIME        SQLT_TIME                   /* SQL/OTS TIME */
#define ACI_TYPECODE_TIME_TZ     SQLT_TIME_TZ             /* SQL/OTS TIME_TZ */
#define ACI_TYPECODE_TIMESTAMP   SQLT_TIMESTAMP         /* SQL/OTS TIMESTAMP */
#define ACI_TYPECODE_TIMESTAMP_TZ  SQLT_TIMESTAMP_TZ /* SQL/OTS TIMESTAMP_TZ */

#define ACI_TYPECODE_TIMESTAMP_LTZ  SQLT_TIMESTAMP_LTZ /* TIMESTAMP_LTZ */

#define ACI_TYPECODE_INTERVAL_YM SQLT_INTERVAL_YM   /* SQL/OTS INTRVL YR-MON */
#define ACI_TYPECODE_INTERVAL_DS SQLT_INTERVAL_DS  /* SQL/OTS INTRVL DAY-SEC */
#define ACI_TYPECODE_UROWID      SQLT_RDD                     /* Urowid type */


#define ACI_TYPECODE_OTMFIRST    228     /* first Open Type Manager typecode */
#define ACI_TYPECODE_OTMLAST     320                    /* last OTM typecode */
#define ACI_TYPECODE_SYSFIRST    228     /* first OTM system type (internal) */
#define ACI_TYPECODE_SYSLAST     235      /* last OTM system type (internal) */
#define ACI_TYPECODE_PLS_INTEGER   266     /* type code for PLS_INTEGER */

/* the following are PL/SQL-only internal. They should not be used */
#define ACI_TYPECODE_ITABLE      SQLT_TAB             /* PLSQL indexed table */
#define ACI_TYPECODE_RECORD      SQLT_REC                    /* PLSQL record */
#define ACI_TYPECODE_BOOLEAN     SQLT_BOL                   /* PLSQL boolean */

/* NOTE : The following NCHAR related codes are just short forms for saying
   ACI_TYPECODE_VARCHAR2 with a charset form of SQLCS_NCHAR. These codes are
   intended for use in the ACIAnyData API only and nowhere else. */
#define ACI_TYPECODE_NCHAR       286
#define ACI_TYPECODE_NVARCHAR2   287
#define ACI_TYPECODE_NCLOB       288


   /* To indicate absence of typecode being specified */
#define ACI_TYPECODE_NONE          0
/* To indicate error has to be taken from error handle - reserved for
   sqlplus use */
#define ACI_TYPECODE_ERRHP         283

   /* The ACITypeCode type is interchangeable with the existing SQLT type
      which is a ub2 */
typedef ub2 ACITypeCode;

enum ACITypeGetOpt
{
	ACI_TYPEGET_HEADER,
	/* load only the header portion of the TDO when getting type */
	ACI_TYPEGET_ALL       /* load all attribute and method descriptors as well */
};
typedef enum ACITypeGetOpt ACITypeGetOpt;

typedef struct ACIRef ACIRef;
/*
 * ACIRef - ACI object REFerence
 *
 * In the Oracle object runtime environment, an object is identified by an
 * object reference (ref) which contains the object identifier plus other
 * runtime information.  The contents of a ref is opaque to clients.  Use
 * ACIObjectNew() to construct a ref.
 */


 /*--------------------------- OBJECT INDICATOR ------------------------------*/

typedef sb2 ACIInd;

/*
 * ACIInd -- a variable of this type contains (null) indicator information
 */

#define ACI_IND_NOTNULL (ACIInd)0                                /* not NULL */
#define ACI_IND_NULL (ACIInd)(-1)                                    /* NULL */
#define ACI_IND_BADNULL (ACIInd)(-2)                             /* BAD NULL */
#define ACI_IND_NOTNULLABLE (ACIInd)(-3)                     /* not NULLable */

 /*---------------------------------------------------------------------------*/
 /*                               OBJECT CACHE                                */
 /*---------------------------------------------------------------------------*/

 /* To enable object change detection mode, set this to TRUE */
#define ACI_ATTR_OBJECT_DETECTCHANGE            0x00000020

/* To enable object creation with  non-NULL attributes by default, set the
   following to TRUE.
   By default, object is created with NULL attributes
*/
#define ACI_ATTR_OBJECT_NEWNOTNULL   0x00000010

/* To enable sorting of the objects that belong to the same table
   before being flushed through ACICacheFlush.
   Please note that by enabling this object cache will not be flushing
   the objects in the same order they were dirtied */
#define ACI_ATTR_CACHE_ARRAYFLUSH 0x00000040

   /*--------------------------- OBJECT PIN OPTION -----------------------------*/

enum ACIPinOpt
{
    /* 0 = uninitialized */
    ACI_PIN_DEFAULT = 1,                                 /* default pin option */
    ACI_PIN_ANY = 3,                          /* pin any copy of the object */
    ACI_PIN_RECENT = 4,                    /* pin recent copy of the object */
    ACI_PIN_LATEST = 5                     /* pin latest copy of the object */
};
typedef enum ACIPinOpt ACIPinOpt;

/*
 * ACIPinOpt - ACI object Pin Option
 *
 * In the Oracle object runtime environment, the program has the option to
 * specify which copy of the object to pin.
 *
 * ACI_PINOPT_DEFAULT pins an object using the default pin option.  The default
 * pin option can be set as an attribute of the ACI environment handle
 * (ACI_ATTR_PINTOPTION).  The value of the default pin option can be
 * ACI_PINOPT_ANY, ACI_PINOPT_RECENT, or ACI_PIN_LATEST. The default option
 * is initialized to ACI_PINOPT_ANY.
 *
 * ACI_PIN_ANY pins any copy of the object.  The object is pinned
 * using the following criteria:
 *   If the object copy is not loaded, load it from the persistent store.
 *   Otherwise, the loaded object copy is returned to the program.
 *
 * ACI_PIN_RECENT pins the latest copy of an object.  The object is
 * pinned using the following criteria:
 *   If the object is not loaded, load the object from the persistent store
 *       from the latest version.
 *   If the object is not loaded in the current transaction and it is not
 *       dirtied, the object is refreshed from the latest version.
 *   Otherwise, the loaded object copy is returned to the program.
 *
 * ACI_PINOPT_LATEST pins the latest copy of an object.  The object copy is
 * pinned using the following criteria:
 *   If the object copy is not loaded, load it from the persistent store.
 *   If the object copy is loaded and dirtied, it is returned to the program.
 *   Otherwise, the loaded object copy is refreshed from the persistent store.
 */

/*--------------------------- OBJECT LOCK OPTION ----------------------------*/

enum ACILockOpt
{
    /* 0 = uninitialized */
    ACI_LOCK_NONE = 1,                               /* null (same as no lock) */
    ACI_LOCK_X = 2,                                          /* exclusive lock */
    ACI_LOCK_X_NOWAIT = 3                      /* exclusive lock, do not wait  */
};
typedef enum ACILockOpt ACILockOpt;
/*
 * ACILockOpt - ACI object LOCK Option
 *
 * This option is used to specify the locking preferences when an object is
 * loaded from the server.
 */


 /*------------------------- OBJECT MODIFYING OPTION -------------------------*/

enum ACIMarkOpt
{
    /* 0 = uninitialized */
    ACI_MARK_DEFAULT = 1,        /* default (the same as ACI_MARK_NONE) */
    ACI_MARK_NONE = ACI_MARK_DEFAULT,   /* object has not been modified */
    ACI_MARK_UPDATE                               /* object is to be updated */
};
typedef enum ACIMarkOpt ACIMarkOpt;
/*
 * ACIMarkOpt - ACI object Mark option
 *
 * When the object is marked updated, the client has to specify how the
 * object is intended to be changed.
 */


/*----------------------------- OBJECT PROPERTY -----------------------------*/

/******************************************************************************
**  DO NOT USE ACIObjectProperty. IT IS UNSUPPORTED                          **
**  WILL BE REMOVED/CHANGED IN A FUTURE RELEASE                              **
******************************************************************************/
enum ACIObjectProperty
{
    /* 0 = uninitialized */
    ACI_OBJECTPROP_DIRTIED = 1,                               /* dirty objects */
    ACI_OBJECTPROP_LOADED,                /* objects loaded in the transaction */
    ACI_OBJECTPROP_LOCKED                                    /* locked objects */
};
typedef enum ACIObjectProperty ACIObjectProperty;
/*
 * ACIObjectProperty -- ACI Object Property
 * This specifies the properties of objects in the object cache.
 */

 /*------------------------- CACHE REFRESH OPTION ---------------------------*/

enum ACIRefreshOpt
{
    /* 0 = uninitialized */
    ACI_REFRESH_LOADED = 1        /* refresh objects loaded in the transaction */
};
typedef enum ACIRefreshOpt ACIRefreshOpt;
/*
 * ACIRefreshOpt - ACI cache Refresh Option
 * This option is used to specify the set of objects to be refreshed.
 *
 * ACI_REFRESH_LOAD refreshes the objects that are loaded in the current
 * transaction.
 */

 /*-------------------------------- OBJECT EVENT -----------------------------*/

 /******************************************************************************
 **  DO NOT USE ACIObjectEvent. IT IS UNSUPPORTED                             **
 **  WILL BE REMOVED/CHANGED IN A FUTURE RELEASE                              **
 ******************************************************************************/
enum ACIObjectEvent
{
    /* 0 = uninitialized */
    ACI_OBJECTEVENT_BEFORE_FLUSH = 1,            /* before flushing the cache */
    ACI_OBJECTEVENT_AFTER_FLUSH,                  /* after flushing the cache */
    ACI_OBJECTEVENT_BEFORE_REFRESH,            /* before refreshing the cache */
    ACI_OBJECTEVENT_AFTER_REFRESH,              /* after refreshing the cache */
    ACI_OBJECTEVENT_WHEN_MARK_UPDATED,    /* when an object is marked updated */
    ACI_OBJECTEVENT_WHEN_MARK_DELETED,    /* when an object is marked deleted */
    ACI_OBJECTEVENT_WHEN_UNMARK,          /* when an object is being unmarked */
    ACI_OBJECTEVENT_WHEN_LOCK               /* when an object is being locked */
};
typedef enum ACIObjectEvent ACIObjectEvent;
/*
 * ACIObjectEvent -- ACI Object Event
 * This specifies the kind of event that is supported by the object
 * cache.  The program can register a callback that is invoked when the
 * specified event occurs.
 */

 /*----------------------------- OBJECT COPY OPTION --------------------------*/
#define ACI_OBJECTCOPY_NOREF (ub1)0x01 
/*
 * ACIObjectCopyFlag - Object copy flag
 *
 * If ACI_OBJECTCOPY_NOREF is specified when copying an instance, the
 * reference and lob will not be copied to the target instance.
 */

 /*----------------------------- OBJECT FREE OPTION --------------------------*/
#define ACI_OBJECTFREE_FORCE      (ub2)0x0001
#define ACI_OBJECTFREE_NONULL     (ub2)0x0002
#define ACI_OBJECTFREE_HEADER     (ub2)0x0004
/*
 * ACIObjectFreeFlag - Object free flag
 *
 * If ACI_OBJECTCOPY_FORCE is specified when freeing an instance, the instance
 * is freed regardless it is pinned or diritied.
 * If ACI_OBJECTCOPY_NONULL is specified when freeing an instance, the null
 * structure is not freed.
 */

 /*----------------------- OBJECT PROPERTY ID -------------------------------*/

typedef ub1 ACIObjectPropId;
#define ACI_OBJECTPROP_LIFETIME 1       /* persistent or transient or value */
#define ACI_OBJECTPROP_SCHEMA 2   /* schema name of table containing object */
#define ACI_OBJECTPROP_TABLE 3     /* table name of table containing object */
#define ACI_OBJECTPROP_PIN_DURATION 4             /* pin duartion of object */
#define ACI_OBJECTPROP_ALLOC_DURATION 5         /* alloc duartion of object */
#define ACI_OBJECTPROP_LOCK 6                      /* lock status of object */
#define ACI_OBJECTPROP_MARKSTATUS 7                /* mark status of object */
#define ACI_OBJECTPROP_VIEW 8            /* is object a view object or not? */

/*
 * ACIObjectPropId - ACI Object Property Id
 * Identifies the different properties of objects.
 */

 /*----------------------- OBJECT LIFETIME ----------------------------------*/
enum ACIObjectLifetime
{
    /* 0 = uninitialized */
    ACI_OBJECT_PERSISTENT = 1,                          /* persistent object */
    ACI_OBJECT_TRANSIENT,                                /* transient object */
    ACI_OBJECT_VALUE                                         /* value object */
};
typedef enum ACIObjectLifetime ACIObjectLifetime;
/*
 * ACIObjectLifetime - ACI Object Lifetime
 * Classifies objects depending upon the lifetime and referenceability
 * of the object.
 */

 /*----------------------- OBJECT MARK STATUS -------------------------------*/

typedef uword ACIObjectMarkStatus;
#define ACI_OBJECT_NEW     0x0001                             /* new object */
#define ACI_OBJECT_DELETED 0x0002                  /* object marked deleted */
#define ACI_OBJECT_UPDATED 0x0004                  /* object marked updated */
/*
 * ACIObjectMarkStatus - ACI Object Mark Status
 * Status of the object - new or updated or deleted
 */

 /* macros to test the object mark status */
#ifndef bit
# define bit(x, y) ((x) & (y))
#endif

#define ACI_OBJECT_IS_UPDATED(flag) bit((flag), ACI_OBJECT_UPDATED)
#define ACI_OBJECT_IS_DELETED(flag) bit((flag), ACI_OBJECT_DELETED)
#define ACI_OBJECT_IS_NEW(flag) bit((flag), ACI_OBJECT_NEW)
#define ACI_OBJECT_IS_DIRTY(flag) \
  bit((flag), ACI_OBJECT_UPDATED|ACI_OBJECT_NEW|ACI_OBJECT_DELETED)



//typedef etc..
/* ACIColl - generic collection type */
typedef struct ACIColl ACIColl;

/* ACIArray - varray collection type */
typedef ACIColl ACIArray;

/* ACITable - nested table collection type */
typedef ACIColl ACITable;

/* ACIIter - collection iterator */
typedef struct ACIIter ACIIter;
/*----------------------------- TYPE DESCRIPTION ----------------------------*/

/*
 * ACIType - ACI Type Description Object
 *
 * The contents of an 'ACIType' is private/opaque to clients.  Clients just
 * need to declare and pass 'ACIType' pointers in to the type manage
 * functions.
 * The pointer points to the type in the object cache.  Thus, clients don't
 * need to allocate space for this type and must NEVER free the pointer to the
 * 'ACIType'.
 */

typedef struct ACIType ACIType;

/*------------------------- TYPE ELEMENT DESCRIPTION ------------------------*/


/*
 * ACITypeElem - ACI Type Element object
 *
 * The contents of an 'ACITypeElem' is private/opaque to clients. Clients just
 * need to declare and pass 'ACITypeElem' pointers in to the type manager
 * functions.
 *
 * 'ACITypeElem' objects contains type element information such as the numeric
 * precision for example, for number objects, and the number of elements for
 * arrays.
 * They ARE used to describe type attributes, collection elements,
 * method parameters, and method results. Hence they are pass in or returned
 * by attribute, collection, and method parameter/result accessors.
 */

typedef struct ACITypeElem ACITypeElem;


/*--------------------------- METHOD DESCRIPTION ---------------------------*/


/*
 * ACITypeMethod - ACI Method Description object
 *
 * The contents of an 'ACITypeMethod' is private/opaque to clients.  Clients
 * just need to declare and pass 'ACITypeMethod' pointers in to the type
 * manager functions.
 * The pointer points to the method in the object cache.  Thus, clients don't
 * need to allocate space for this type and must NEVER free the pointer to
 * the 'ACITypeMethod'.
 */

typedef struct ACITypeMethod ACITypeMethod;


/*--------------------------- TYPE ACCESS ITERATOR --------------------------*/

/*
 * ACITypeIter- ACI Type Iterator
 *
 * The contents of an 'orti' is private/opaque to clients.  Clients just
 * need to declare and pass 'orti' pointers in to the type manager functions.
 * The iterator is used to retreive MDO's and ADO's that belong to the TDO
 * one at a time. It needs to be allocated by the 'ACITypeIterNew()' function
 * call and deallocated with the 'ACITypeIterFree()' function call.
 */

typedef struct ACITypeIter ACITypeIter;


#endif //!_OBJ_HEADER__INCLUDE__