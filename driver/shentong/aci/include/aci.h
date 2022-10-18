#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "acitype.h"

/*--------------------------------------------------------------------------- 
                     PUBLIC TYPES AND CONSTANTS 
  ---------------------------------------------------------------------------*/

/*-----------------------------Handle Types----------------------------------*/
                                           /* handle types range from 1 - 49 */
#define ACI_HTYPE_FIRST          1             /* start value of handle type */
#define ACI_HTYPE_ENV            1                     /* environment handle */
#define ACI_HTYPE_ERROR          2                           /* error handle */
#define ACI_HTYPE_SVCCTX         3                         /* service handle */
#define ACI_HTYPE_STMT           4                       /* statement handle */
#define ACI_HTYPE_BIND           5                            /* bind handle */
#define ACI_HTYPE_DEFINE         6                          /* define handle */
#define ACI_HTYPE_DESCRIBE       7                        /* describe handle */
#define ACI_HTYPE_SERVER         8                          /* server handle */
#define ACI_HTYPE_SESSION        9                  /* authentication handle */
#define ACI_HTYPE_AUTHINFO      ACI_HTYPE_SESSION  /* SessionGet auth handle */
#define ACI_HTYPE_TRANS         10                     /* transaction handle */
#define ACI_HTYPE_COMPLEXOBJECT 11        /* complex object retrieval handle */
#define ACI_HTYPE_SECURITY      12                        /* security handle */
#define ACI_HTYPE_SUBSCRIPTION  13                    /* subscription handle */
#define ACI_HTYPE_DIRPATH_CTX   14                    /* direct path context */
#define ACI_HTYPE_DIRPATH_COLUMN_ARRAY 15        /* direct path column array */
#define ACI_HTYPE_DIRPATH_STREAM       16              /* direct path stream */
#define ACI_HTYPE_PROC                 17                  /* process handle */
#define ACI_HTYPE_DIRPATH_FN_CTX       18    /* direct path function context */
#define ACI_HTYPE_DIRPATH_FN_COL_ARRAY 19          /* dp object column array */
#define ACI_HTYPE_XADSESSION    20                  /* access driver session */
#define ACI_HTYPE_XADTABLE      21                    /* access driver table */
#define ACI_HTYPE_XADFIELD      22                    /* access driver field */
#define ACI_HTYPE_XADGRANULE    23                  /* access driver granule */
#define ACI_HTYPE_XADRECORD     24                   /* access driver record */
#define ACI_HTYPE_XADIO         25                      /* access driver I/O */
#define ACI_HTYPE_CPOOL         26                 /* connection pool handle */
#define ACI_HTYPE_SPOOL         27                    /* session pool handle */
#define ACI_HTYPE_ADMIN         28                           /* admin handle */
#define ACI_HTYPE_EVENT         29                        /* HA event handle */
#define ACI_HTYPE_BULKIMP		30						
#define ACI_HTYPE_BULK   		31
#define ACI_HTYPE_RAW   		32

#define ACI_HTYPE_LAST          32            /* last value of a handle type */

/*---------------------------------------------------------------------------*/


/*-------------------------Descriptor Types----------------------------------*/
                                    /* descriptor values range from 50 - 255 */
#define ACI_DTYPE_FIRST 50                 /* start value of descriptor type */
#define ACI_DTYPE_LOB 50                                     /* lob  locator */
#define ACI_DTYPE_SNAP 51                             /* snapshot descriptor */
#define ACI_DTYPE_RSET 52                           /* result set descriptor */
#define ACI_DTYPE_PARAM 53  /* a parameter descriptor obtained from acigparm */
#define ACI_DTYPE_ROWID  54                              /* rowid descriptor */
#define ACI_DTYPE_COMPLEXOBJECTCOMP  55
                                      /* complex object retrieval descriptor */
#define ACI_DTYPE_FILE 56                                /* File Lob locator */
#define ACI_DTYPE_AQENQ_OPTIONS 57                        /* enqueue options */
#define ACI_DTYPE_AQDEQ_OPTIONS 58                        /* dequeue options */
#define ACI_DTYPE_AQMSG_PROPERTIES 59                  /* message properties */
#define ACI_DTYPE_AQAGENT 60                                     /* aq agent */
#define ACI_DTYPE_LOCATOR 61                                  /* LOB locator */
#define ACI_DTYPE_INTERVAL_YM 62                      /* Interval year month */
#define ACI_DTYPE_INTERVAL_DS 63                      /* Interval day second */
#define ACI_DTYPE_AQNFY_DESCRIPTOR  64               /* AQ notify descriptor */
#define ACI_DTYPE_DATE 65                            /* Date */
#define ACI_DTYPE_TIME 66                            /* Time */
#define ACI_DTYPE_TIME_TZ 67                         /* Time with timezone */
#define ACI_DTYPE_TIMESTAMP 68                       /* Timestamp */
#define ACI_DTYPE_TIMESTAMP_TZ 69                /* Timestamp with timezone */
#define ACI_DTYPE_TIMESTAMP_LTZ 70             /* Timestamp with local tz */
#define ACI_DTYPE_UCB           71               /* user callback descriptor */
#define ACI_DTYPE_SRVDN         72              /* server DN list descriptor */
#define ACI_DTYPE_SIGNATURE     73                              /* signature */
#define ACI_DTYPE_RESERVED_1    74              /* reserved for internal use */
#define ACI_DTYPE_AQLIS_OPTIONS 75                      /* AQ listen options */
#define ACI_DTYPE_AQLIS_MSG_PROPERTIES 76             /* AQ listen msg props */
#define ACI_DTYPE_CHDES         77          /* Top level change notification desc */
#define ACI_DTYPE_TABLE_CHDES   78          /* Table change descriptor           */
#define ACI_DTYPE_ROW_CHDES     79          /* Row change descriptor            */
#define ACI_DTYPE_JSON			80          /*Json descriptor            */
#define ACI_DTYPE_LAST          80        /* last value of a descriptor type */

/*---------------------------------------------------------------------------*/

/*--------------------------------LOB types ---------------------------------*/
#define ACI_TEMP_BLOB  1                /* LOB type - BLOB ------------------ */
#define ACI_TEMP_CLOB  2                /* LOB type - CLOB ------------------ */
#define ACI_TEMP_BFILE 3                /* LOB type - BFILE ----------------- */
/*---------------------------------------------------------------------------*/

/*-------------------------Object Ptr Types----------------------------------*/
#define ACI_OTYPE_NAME 1                                      /* object name */
#define ACI_OTYPE_REF  2                                       /* REF to TDO */
#define ACI_OTYPE_PTR  3                                       /* PTR to TDO */
/*---------------------------------------------------------------------------*/

/*-------------------------- OBJECT Duration --------------------------------*/

typedef ub2 ACIDuration;

#define  ACI_DURATION_INVALID 0xFFFF                     /* Invalid duration */
#define  ACI_DURATION_BEGIN (ACIDuration)10
/* beginning sequence of duration */
#define  ACI_DURATION_NULL (ACIDuration)(ACI_DURATION_BEGIN-1)
                                                            /* null duration */
#define  ACI_DURATION_DEFAULT (ACIDuration)(ACI_DURATION_BEGIN-2) /* default */
#define  ACI_DURATION_USER_CALLBACK (ACIDuration)(ACI_DURATION_BEGIN-3)
#define  ACI_DURATION_NEXT (ACIDuration)(ACI_DURATION_BEGIN-4)
                                                    /* next special duration */
#define  ACI_DURATION_SESSION (ACIDuration)(ACI_DURATION_BEGIN)
                                                  /* the end of user session */
#define  ACI_DURATION_TRANS (ACIDuration)(ACI_DURATION_BEGIN+1)
                                              /* the end of user transaction */
/******************************************************************************
**  DO NOT USE ACI_DURATION_CALL. IT  IS UNSUPPORTED                         **
**  WILL BE REMOVED/CHANGED IN A FUTURE RELEASE                              **
******************************************************************************/
#define  ACI_DURATION_CALL (ACIDuration)(ACI_DURATION_BEGIN+2)
/* the end of user client/server call */
#define  ACI_DURATION_STATEMENT (ACIDuration)(ACI_DURATION_BEGIN+3)

/* This is to be used only during callouts.  It is similar to that
of ACI_DURATION_CALL, but lasts only for the duration of a callout.
Its heap is from PGA */
#define  ACI_DURATION_CALLOUT (ACIDuration)(ACI_DURATION_BEGIN+4)

#define  ACI_DURATION_LAST ACI_DURATION_CALLOUT 
/* last of predefined durations */

/* This is not being treated as other predefined durations such as
   SESSION, CALL etc, because this would not have an entry in the duration
   table and its functionality is primitive such that only allocate, free,
   resize memory are allowed, but one cannot create subduration out of this
*/
#define  ACI_DURATION_PROCESS (ACIDuration)(ACI_DURATION_BEGIN-5) 

/*
 * ACIDuration - ACI object duration
 *
 * A client can specify the duration of which an object is pinned (pin
 * duration) and the duration of which the object is in memory (allocation
 * duration).  If the objects are still pinned at the end of the pin duration,
 * the object cache manager will automatically unpin the objects for the
 * client. If the objects still exist at the end of the allocation duration,
 * the object cache manager will automatically free the objects for the client.
 *
 * Objects that are pinned with the option ACI_DURATION_TRANS will get unpinned
 * automatically at the end of the current transaction.
 *
 * Objects that are pinned with the option ACI_DURATION_SESSION will get
 * unpinned automatically at the end of the current session (connection).
 *
 * The option ACI_DURATION_NULL is used when the client does not want to set
 * the pin duration.  If the object is already loaded into the cache, then the
 * pin duration will remain the same.  If the object is not yet loaded, the
 * pin duration of the object will be set to ACI_DURATION_DEFAULT.
 */

/*=============================Attribute Types===============================*/
/* 
   Note: All attributes are global.  New attibutes should be added to the end
   of the list. Before you add an attribute see if an existing one can be 
   used for your handle. 

   If you see any holes please use the holes first. 
 
*/
/*===========================================================================*/


#define ACI_ATTR_FNCODE  1                          /* the ACI function code */
#define ACI_ATTR_OBJECT   2 /* is the environment initialized in object mode */
#define ACI_ATTR_NONBLOCKING_MODE  3                    /* non blocking mode */
#define ACI_ATTR_SQLCODE  4                                  /* the SQL verb */
#define ACI_ATTR_ENV  5                            /* the environment handle */
#define ACI_ATTR_SERVER 6                               /* the server handle */
#define ACI_ATTR_SESSION 7                        /* the user session handle */
#define ACI_ATTR_TRANS   8                         /* the transaction handle */
#define ACI_ATTR_ROW_COUNT   9                  /* the rows processed so far */
#define ACI_ATTR_SQLFNCODE 10               /* the SQL verb of the statement */
#define ACI_ATTR_PREFETCH_ROWS  11    /* sets the number of rows to prefetch */
#define ACI_ATTR_NESTED_PREFETCH_ROWS 12 /* the prefetch rows of nested table*/
#define ACI_ATTR_PREFETCH_MEMORY 13         /* memory limit for rows fetched */
#define ACI_ATTR_NESTED_PREFETCH_MEMORY 14   /* memory limit for nested rows */
#define ACI_ATTR_CHAR_COUNT  15 
                    /* this specifies the bind and define size in characters */
#define ACI_ATTR_PDSCL   16                          /* packed decimal scale */
#define ACI_ATTR_FSPRECISION ACI_ATTR_PDSCL   
                                          /* fs prec for datetime data types */
#define ACI_ATTR_PDPRC   17                         /* packed decimal format */
#define ACI_ATTR_LFPRECISION ACI_ATTR_PDPRC 
                                          /* fs prec for datetime data types */
#define ACI_ATTR_PARAM_COUNT 18       /* number of column in the select list */
#define ACI_ATTR_ROWID   19                                     /* the rowid */
#define ACI_ATTR_CHARSET  20                      /* the character set value */
#define ACI_ATTR_NCHAR   21                                    /* NCHAR type */
#define ACI_ATTR_USERNAME 22                           /* username attribute */
#define ACI_ATTR_PASSWORD 23                           /* password attribute */
#define ACI_ATTR_STMT_TYPE   24                            /* statement type */
#define ACI_ATTR_INTERNAL_NAME   25             /* user friendly global name */
#define ACI_ATTR_EXTERNAL_NAME   26      /* the internal name for global txn */
#define ACI_ATTR_XID     27           /* XOPEN defined global transaction id */
#define ACI_ATTR_TRANS_LOCK 28                                            /* */
#define ACI_ATTR_TRANS_NAME 29    /* string to identify a global transaction */
#define ACI_ATTR_HEAPALLOC 30                /* memory allocated on the heap */
#define ACI_ATTR_CHARSET_ID 31                           /* Character Set ID */
#define ACI_ATTR_CHARSET_FORM 32                       /* Character Set Form */
#define ACI_ATTR_MAXDATA_SIZE 33       /* Maximumsize of data on the server  */
#define ACI_ATTR_CACHE_OPT_SIZE 34              /* object cache optimal size */
#define ACI_ATTR_CACHE_MAX_SIZE 35   /* object cache maximum size percentage */
#define ACI_ATTR_PINOPTION 36             /* object cache default pin option */
#define ACI_ATTR_ALLOC_DURATION 37
                                 /* object cache default allocation duration */
#define ACI_ATTR_PIN_DURATION 38        /* object cache default pin duration */
#define ACI_ATTR_FDO          39       /* Format Descriptor object attribute */
#define ACI_ATTR_POSTPROCESSING_CALLBACK 40
                                         /* Callback to process outbind data */
#define ACI_ATTR_POSTPROCESSING_CONTEXT 41
                                 /* Callback context to process outbind data */
#define ACI_ATTR_ROWS_RETURNED 42
               /* Number of rows returned in current iter - for Bind handles */
#define ACI_ATTR_FOCBK        43              /* Failover Callback attribute */
#define ACI_ATTR_IN_V8_MODE   44 /* is the server/service context in V8 mode */
#define ACI_ATTR_LOBEMPTY     45                              /* empty lob ? */
#define ACI_ATTR_SESSLANG     46                  /* session language handle */
#define ACI_ATTR_BREAK_ON_NET_TIMEOUT      495           /* Break on timeout */

#define ACI_ATTR_VISIBILITY             47                     /* visibility */
#define ACI_ATTR_RELATIVE_MSGID         48            /* relative message id */
#define ACI_ATTR_SEQUENCE_DEVIATION     49             /* sequence deviation */

#define ACI_ATTR_CONSUMER_NAME          50                  /* consumer name */
#define ACI_ATTR_DEQ_MODE               51                   /* dequeue mode */
#define ACI_ATTR_NAVIGATION             52                     /* navigation */
#define ACI_ATTR_WAIT                   53                           /* wait */
#define ACI_ATTR_DEQ_MSGID              54             /* dequeue message id */

#define ACI_ATTR_PRIORITY               55                       /* priority */
#define ACI_ATTR_DELAY                  56                          /* delay */
#define ACI_ATTR_EXPIRATION             57                     /* expiration */
#define ACI_ATTR_CORRELATION            58                 /* correlation id */
#define ACI_ATTR_ATTEMPTS               59                  /* # of attempts */
#define ACI_ATTR_RECIPIENT_LIST         60                 /* recipient list */
#define ACI_ATTR_EXCEPTION_QUEUE        61           /* exception queue name */
#define ACI_ATTR_ENQ_TIME               62 /* enqueue time (only ACIAttrGet) */
#define ACI_ATTR_MSG_STATE              63/* message state (only ACIAttrGet) */
                                                   /* NOTE: 64-66 used below */
#define ACI_ATTR_AGENT_NAME             64                     /* agent name */
#define ACI_ATTR_AGENT_ADDRESS          65                  /* agent address */
#define ACI_ATTR_AGENT_PROTOCOL         66                 /* agent protocol */
#define ACI_ATTR_USER_PROPERTY          67                  /* user property */
#define ACI_ATTR_SENDER_ID              68                      /* sender id */
#define ACI_ATTR_ORIGINAL_MSGID         69            /* original message id */

#define ACI_ATTR_QUEUE_NAME             70                     /* queue name */
#define ACI_ATTR_NFY_MSGID              71                     /* message id */
#define ACI_ATTR_MSG_PROP               72             /* message properties */

#define ACI_ATTR_NUM_DML_ERRORS         73       /* num of errs in array DML */
#define ACI_ATTR_DML_ROW_OFFSET         74        /* row offset in the array */

              /* AQ array error handling uses DML method of accessing errors */
#define ACI_ATTR_AQ_NUM_ERRORS          ACI_ATTR_NUM_DML_ERRORS
#define ACI_ATTR_AQ_ERROR_INDEX         ACI_ATTR_DML_ROW_OFFSET

#define ACI_ATTR_DATEFORMAT             75     /* default date format string */
#define ACI_ATTR_BUF_ADDR               76                 /* buffer address */
#define ACI_ATTR_BUF_SIZE               77                    /* buffer size */

/* For values 78 - 80, see DirPathAPI attribute section in this file */

#define ACI_ATTR_NUM_ROWS               81 /* number of rows in column array */
                                  /* NOTE that ACI_ATTR_NUM_COLS is a column
                                   * array attribute too.
                                   */
#define ACI_ATTR_COL_COUNT              82        /* columns of column array
                                                     processed so far.       */
#define ACI_ATTR_STREAM_OFFSET          83  /* str off of last row processed */
#define ACI_ATTR_SHARED_HEAPALLOC       84    /* Shared Heap Allocation Size */

#define ACI_ATTR_SERVER_GROUP           85              /* server group name */

#define ACI_ATTR_MIGSESSION             86   /* migratable session attribute */

#define ACI_ATTR_NOCACHE                87                 /* Temporary LOBs */

#define ACI_ATTR_MEMPOOL_SIZE           88                      /* Pool Size */
#define ACI_ATTR_MEMPOOL_INSTNAME       89                  /* Instance name */
#define ACI_ATTR_MEMPOOL_APPNAME        90               /* Application name */
#define ACI_ATTR_MEMPOOL_HOMENAME       91            /* Home Directory name */
#define ACI_ATTR_MEMPOOL_MODEL          92     /* Pool Model (proc,thrd,both)*/
#define ACI_ATTR_MODES                  93                          /* Modes */

#define ACI_ATTR_SUBSCR_NAME            94           /* name of subscription */
#define ACI_ATTR_SUBSCR_CALLBACK        95            /* assaciated callback */
#define ACI_ATTR_SUBSCR_CTX             96    /* assaciated callback context */
#define ACI_ATTR_SUBSCR_PAYLOAD         97             /* assaciated payload */
#define ACI_ATTR_SUBSCR_NAMESPACE       98           /* assaciated namespace */

#define ACI_ATTR_PROXY_CREDENTIALS      99         /* Proxy user credentials */
#define ACI_ATTR_INITIAL_CLIENT_ROLES  100       /* Initial client role list */

#define ACI_ATTR_UNK              101                   /* unknown attribute */
#define ACI_ATTR_NUM_COLS         102                   /* number of columns */
#define ACI_ATTR_LIST_COLUMNS     103        /* parameter of the column list */
#define ACI_ATTR_RDBA             104           /* DBA of the segment header */
#define ACI_ATTR_CLUSTERED        105      /* whether the table is clustered */
#define ACI_ATTR_PARTITIONED      106    /* whether the table is partitioned */
#define ACI_ATTR_INDEX_ONLY       107     /* whether the table is index only */
#define ACI_ATTR_LIST_ARGUMENTS   108      /* parameter of the argument list */
#define ACI_ATTR_LIST_SUBPROGRAMS 109    /* parameter of the subprogram list */
#define ACI_ATTR_REF_TDO          110          /* REF to the type descriptor */
#define ACI_ATTR_LINK             111              /* the database link name */
#define ACI_ATTR_MIN              112                       /* minimum value */
#define ACI_ATTR_MAX              113                       /* maximum value */
#define ACI_ATTR_INCR             114                     /* increment value */
#define ACI_ATTR_CACHE            115   /* number of sequence numbers cached */
#define ACI_ATTR_ORDER            116     /* whether the sequence is ordered */
#define ACI_ATTR_HW_MARK          117                     /* high-water mark */
#define ACI_ATTR_TYPE_SCHEMA      118                  /* type's schema name */
#define ACI_ATTR_TIMESTAMP        119             /* timestamp of the object */
#define ACI_ATTR_NUM_ATTRS        120                /* number of sttributes */
#define ACI_ATTR_NUM_PARAMS       121                /* number of parameters */
#define ACI_ATTR_OBJID            122       /* object id for a table or view */
#define ACI_ATTR_PTYPE            123           /* type of info described by */
#define ACI_ATTR_PARAM            124                /* parameter descriptor */
#define ACI_ATTR_OVERLOAD_ID      125     /* overload ID for funcs and procs */
#define ACI_ATTR_TABLESPACE       126                    /* table name space */
#define ACI_ATTR_TDO              127                       /* TDO of a type */
#define ACI_ATTR_LTYPE            128                           /* list type */
#define ACI_ATTR_PARSE_ERROR_OFFSET 129                /* Parse Error offset */
#define ACI_ATTR_IS_TEMPSTRY     130          /* whether table is temporary */
#define ACI_ATTR_IS_TYPED         131              /* whether table is typed */
#define ACI_ATTR_DURATION         132         /* duration of temporary table */
#define ACI_ATTR_IS_INVOKER_RIGHTS 133                  /* is invoker rights */
#define ACI_ATTR_OBJ_NAME         134           /* top level schema obj name */
#define ACI_ATTR_OBJ_SCHEMA       135                         /* schema name */
#define ACI_ATTR_OBJ_ID           136          /* top level schema object id */

/* For values 137 - 141, see DirPathAPI attribute section in this file */


#define ACI_ATTR_TRANS_TIMEOUT              142       /* transaction timeout */
#define ACI_ATTR_SERVER_STATUS              143/* state of the server handle */
#define ACI_ATTR_STATEMENT                  144 /* statement txt in stmt hdl */

/* For value 145, see DirPathAPI attribute section in this file */

#define ACI_ATTR_DEQCOND                    146         /* dequeue condition */
#define ACI_ATTR_RESERVED_2                 147                  /* reserved */

  
#define ACI_ATTR_SUBSCR_RECPT               148 /* recepient of subscription */
#define ACI_ATTR_SUBSCR_RECPTPROTO          149    /* protocol for recepient */

/* For values 150 - 151, see DirPathAPI attribute section in this file */

#define ACI_ATTR_LDAP_HOST       153              /* LDAP host to connect to */
#define ACI_ATTR_LDAP_PORT       154              /* LDAP port to connect to */
#define ACI_ATTR_BIND_DN         155                              /* bind DN */
#define ACI_ATTR_LDAP_CRED       156       /* credentials to connect to LDAP */
#define ACI_ATTR_WALL_LOC        157               /* client wallet location */
#define ACI_ATTR_LDAP_AUTH       158           /* LDAP authentication method */
#define ACI_ATTR_LDAP_CTX        159        /* LDAP adminstration context DN */
#define ACI_ATTR_SERVER_DNS      160      /* list of registration server DNs */

#define ACI_ATTR_DN_COUNT        161             /* the number of server DNs */
#define ACI_ATTR_SERVER_DN       162                  /* server DN attribute */

#define ACI_ATTR_MAXCHAR_SIZE               163     /* max char size of data */

#define ACI_ATTR_CURRENT_POSITION           164 /* for scrollable result sets*/

/* Added to get attributes for ref cursor to statement handle */
#define ACI_ATTR_RESERVED_3                 165                  /* reserved */
#define ACI_ATTR_RESERVED_4                 166                  /* reserved */

/* For value 167, see DirPathAPI attribute section in this file */

#define ACI_ATTR_DIGEST_ALGO                168          /* digest algorithm */
#define ACI_ATTR_CERTIFICATE                169               /* certificate */
#define ACI_ATTR_SIGNATURE_ALGO             170       /* signature algorithm */
#define ACI_ATTR_CANONICAL_ALGO             171    /* canonicalization algo. */
#define ACI_ATTR_PRIVATE_KEY                172               /* private key */
#define ACI_ATTR_DIGEST_VALUE               173              /* digest value */
#define ACI_ATTR_SIGNATURE_VAL              174           /* signature value */
#define ACI_ATTR_SIGNATURE                  175                 /* signature */

/* attributes for setting ACI stmt caching specifics in svchp */
#define ACI_ATTR_STMTCACHESIZE              176     /* size of the stm cache */
#define ACI_ATTR_SESSGET_FLAGS              177 /* OCISessionGet returned flags */

/* --------------------------- Connection Pool Attributes ------------------ */
#define ACI_ATTR_CONN_NOWAIT               178
#define ACI_ATTR_CONN_BUSY_COUNT            179
#define ACI_ATTR_CONN_OPEN_COUNT            180
#define ACI_ATTR_CONN_TIMEOUT               181
#define ACI_ATTR_STMT_STATE                 182
#define ACI_ATTR_CONN_MIN                   183
#define ACI_ATTR_CONN_MAX                   184
#define ACI_ATTR_CONN_INCR                  185

/* --------------------------- Session Pool Attributes ------------------ */
#define ACI_ATTR_SPOOL_AUTH						460
#define ACI_ATTR_SPOOL_TIMEOUT					308           /* session timeout */
#define ACI_ATTR_SPOOL_GETMODE					309          /* session get mode */
#define ACI_ATTR_SPOOL_BUSY_COUNT				310        /* busy session count */
#define ACI_ATTR_SPOOL_OPEN_COUNT				311        /* open session count */
#define ACI_ATTR_SPOOL_MIN						312         /* min session count */
#define ACI_ATTR_SPOOL_MAX						313         /* max session count */
#define ACI_ATTR_SPOOL_INCR						314		/* session increment count */

#define ACI_ATTR_SPOOL_MAX_LIFETIME_SESSION     490		/* Max Lifetime for session */
#define ACI_ATTR_SPOOL_MAX_USE_SESSION          580
#define ACI_ATTR_SPOOL_STMTCACHESIZE			208
#define ACI_ATTR_SPOOL_WAIT_TIMEOUT				506
#define ACI_ATTR_SPOOL_MAX_PER_SHARD			602
#define ACI_ATTR_SPOOL_DRAIN_TIMEOUT			1		/* 待定值 */

#define ACI_ATTR_VARTYPE_MAXLEN_COMPAT          489

#define ACI_ATTR_SQL_ID                    504                /* SQL ID in text form */
#define ACI_ATTR_COLLATION_ID              499                /* Collation ID */
#define ACI_ATTR_COL_PROPERTIES 104                           /* column properties */
#define ACI_ATTR_INVISIBLE_COL             461                /* invisible columns support */

/* For value 187, see DirPathAPI attribute section in this file */

#define ACI_ATTR_NUM_OPEN_STMTS             188     /* open stmts in session */
#define ACI_ATTR_DESCRIBE_NATIVE            189  /* get native info via desc */

#define ACI_ATTR_BIND_COUNT                 190   /* number of bind postions */
#define ACI_ATTR_HANDLE_POSITION            191 /* pos of bind/define handle */
#define ACI_ATTR_RESERVED_5                 192                 /* reserverd */
#define ACI_ATTR_SERVER_BUSY                193 /* call in progress on server*/

/* For value 194, see DirPathAPI attribute section in this file */

/* notification presentation for recipient */
#define ACI_ATTR_SUBSCR_RECPTPRES           195
#define ACI_ATTR_TRANSFORMATION             196 /* AQ message transformation */

#define ACI_ATTR_ROWS_FETCHED               197 /* rows fetched in last call */

/* --------------------------- Snapshot attributes ------------------------- */
#define ACI_ATTR_SCN_BASE                   198             /* snapshot base */
#define ACI_ATTR_SCN_WRAP                   199             /* snapshot wrap */

/* --------------------------- Miscellanous attributes --------------------- */
#define ACI_ATTR_RESERVED_6                 200                  /* reserved */
#define ACI_ATTR_READONLY_TXN               201           /* txn is readonly */
#define ACI_ATTR_RESERVED_7                 202                  /* reserved */
#define ACI_ATTR_ERRONEOUS_COLUMN           203 /* position of erroneous col */
#define ACI_ATTR_RESERVED_8                 204                  /* reserved */

/* For value 206, see DirPathAPI attribute section in this file */

#define ACI_ATTR_INST_TYPE                  207      /* oracle instance type */
/******USED attribute 208 for  ACI_ATTR_SPOOL_STMTCACHESIZE*******************/

#define ACI_ATTR_ENV_UTF16                  209     /* is env in utf16 mode? */
#define ACI_ATTR_ENV_NLS_LANGUAGE           424 
#define ACI_ATTR_ENV_NLS_TERRITORY          425 
#define ACI_ATTR_RESERVED_9                 210          /* reserved for TMZ */
#define ACI_ATTR_RESERVED_10                211                  /* reserved */

/* For values 212 and 213, see DirPathAPI attribute section in this file */

#define ACI_ATTR_RESERVED_12                214                  /* reserved */
#define ACI_ATTR_RESERVED_13                215                  /* reserved */
#define ACI_ATTR_IS_EXTERNAL                216 /* whether table is external */


/* -------------------------- Statement Handle Attributes ------------------ */

#define ACI_ATTR_RESERVED_15                217                  /* reserved */
#define ACI_ATTR_STMT_IS_RETURNING          218 /* stmt has returning clause */
#define ACI_ATTR_RESERVED_16                219                  /* reserved */
#define ACI_ATTR_RESERVED_17                220                  /* reserved */
#define ACI_ATTR_RESERVED_18                221                  /* reserved */

/* --------------------------- session attributes ---------------------------*/
#define ACI_ATTR_RESERVED_19                222                  /* reserved */
#define ACI_ATTR_RESERVED_20                223                  /* reserved */
#define ACI_ATTR_CURRENT_SCHEMA             224            /* Current Schema */
#define ACI_ATTR_RESERVED_21                415                  /* reserved */

/* ------------------------- notification subscription ----------------------*/
#define ACI_ATTR_SUBSCR_QOSFLAGS            225                 /* QOS flags */
#define ACI_ATTR_SUBSCR_PAYLOADCBK          226          /* Payload callback */
#define ACI_ATTR_SUBSCR_TIMEOUT             227                   /* Timeout */
#define ACI_ATTR_SUBSCR_NAMESPACE_CTX       228         /* Namespace context */

#define ACI_ATTR_EDITION                   288                /* ORA_EDITION */

/* ----------------------- row callback attributes ------------------------- */
#define ACI_ATTR_BIND_ROWCBK                301         /* bind row callback */
#define ACI_ATTR_BIND_ROWCTX                302 /* ctx for bind row callback */
#define ACI_ATTR_SKIP_BUFFER                303  /* skip buffer in array ops */

/* ----------------------- socket mark ------------------------- */
#define ACI_ATTR_SOCK_MARK                  360
#define ACI_ATTR_SOCK_MARK_NAME				361
#define ACI_ATTR_SOCK_MARK_AFTERSOCKET      362
#define ACI_ATTR_SOCK_MARK_AFTERCONNECT     363

/* ------------- DB Change Notification reg handle attributes ---------------*/
#define ACI_ATTR_CHNF_TABLENAMES          401     /* out: array of table names     */
#define ACI_ATTR_CHNF_ROWIDS              402     /* in: rowids needed */ 
#define ACI_ATTR_CHNF_OPERATIONS          403  /* in: notification operation filter*/ 
#define ACI_ATTR_CHNF_CHANGELAG           404  /* txn lag between notifications  */

/* DB Change: Notification Descriptor attributes -----------------------*/
#define ACI_ATTR_CHDES_DBNAME            405    /* source database    */
#define ACI_ATTR_CHDES_NFYTYPE           406    /* notification type flags */
#define ACI_ATTR_CHDES_XID               407    /* XID  of the transaction */
#define ACI_ATTR_CHDES_TABLE_CHANGES     408    /* array of table chg descriptors */

#define ACI_ATTR_CHDES_TABLE_NAME        409    /* table name */
#define ACI_ATTR_CHDES_TABLE_OPFLAGS     410    /* table operation flags */
#define ACI_ATTR_CHDES_TABLE_ROW_CHANGES 411   /* array of changed rows   */
#define ACI_ATTR_CHDES_ROW_ROWID         412   /* rowid of changed row    */
#define ACI_ATTR_CHDES_ROW_OPFLAGS       413   /* row operation flags     */

/* Statement handle attribute for db change notification */
#define ACI_ATTR_CHNF_REGHANDLE          414   /* IN: subscription handle  */

/* client name for single session proxy */
#define ACI_ATTR_PROXY_CLIENT            416

/* 415 is already taken - see ACI_ATTR_RESERVED_21 */

/* TDE attributes on the Table */
#define ACI_ATTR_TABLE_ENC         417/* does table have any encrypt columns */
#define ACI_ATTR_TABLE_ENC_ALG     418         /* Table encryption Algorithm */
#define ACI_ATTR_TABLE_ENC_ALG_ID  419 /* Internal Id of encryption Algorithm*/

/*--------- Attributes related to LOB prefetch------------------------------ */
#define ACI_ATTR_DEFAULT_LOBPREFETCH_SIZE     438   /* default prefetch size */
#define ACI_ATTR_LOBPREFETCH_SIZE             439           /* prefetch size */
#define ACI_ATTR_LOBPREFETCH_LENGTH           440 /* prefetch length & chunk */

/* statement attribute */
#define ACI_ATTR_UB8_ROW_COUNT         457         /* ub8 value of row count */
#define ACI_ATTR_IMPLICIT_RESULT_COUNT      463

#define ACI_ATTR_CALL_TIMEOUT              531     /*operation level timeout or fine grained timers for operations*/

/* -------- Attributes for Network Session Time Out--------------------------*/
#define ACI_ATTR_SEND_TIMEOUT               435           /* NS send timeout */
#define ACI_ATTR_RECEIVE_TIMEOUT            436        /* NS receive timeout */

#define ACI_ATTR_RESERVED_35                437

/*--------------------Attribute to fetch ROWID ------------------------------*/
#define ACI_ATTR_FETCH_ROWID              448

/* Please use from 143 */

/* DB Change: Event types ---------------*/
#define ACI_EVENT_NONE 0x0                      /* None */
#define ACI_EVENT_STARTUP 0x1                   /* Startup database */
#define ACI_EVENT_SHUTDOWN 0x2                  /* Shutdown database */
#define ACI_EVENT_SHUTDOWN_ANY 0x3              /* Startup instance */
#define ACI_EVENT_DROP_DB 0x4                   /* Drop database    */
#define ACI_EVENT_DEREG 0x5                     /* Subscription deregistered */
#define ACI_EVENT_OBJCHANGE 0x6                 /* Object change notification */

/* DB Change: Operation types -----------*/
#define ACI_OPCODE_ALLROWS 0x1                 /* all rows invalidated  */
#define ACI_OPCODE_ALLOPS 0x0                  /* interested in all operations */
#define ACI_OPCODE_INSERT 0x2                 /*  INSERT */
#define ACI_OPCODE_UPDATE 0x4                 /*  UPDATE */
#define ACI_OPCODE_DELETE 0x8                 /* DELETE */
#define ACI_OPCODE_ALTER 0x10                 /* ALTER */
#define ACI_OPCODE_DROP 0x20                  /* DROP TABLE */
#define ACI_OPCODE_UNKNOWN 0x40               /* GENERIC/ UNKNOWN*/

/* -------- client side character and national character set ids ----------- */
#define ACI_ATTR_ENV_CHARSET_ID   ACI_ATTR_CHARSET_ID   /* charset id in env */
#define ACI_ATTR_ENV_NCHARSET_ID  ACI_ATTR_NCHARSET_ID /* ncharset id in env */

/* ----------------------- ha event callback attributes -------------------- */
#define ACI_ATTR_EVTCBK                     304               /* ha callback */
#define ACI_ATTR_EVTCTX                     305       /* ctx for ha callback */

#define ACI_ATTR_STMTCACHE_CBKCTX  420             /* opaque context on stmt */
#define ACI_ATTR_STMTCACHE_CBK     421          /* callback fn for stmtcache */

/* ------------------ User memory attributes (all handles) ----------------- */
#define ACI_ATTR_USER_MEMORY               306     /* pointer to user memory */

/* ----------------- port no attribute in subscription handle  ------------- */
#define ACI_ATTR_SUBSCR_PORTNO              390  /* port no to listen        */

/*------------- Supported Values for protocol for recepient -----------------*/
#define ACI_SUBSCR_PROTO_ACI                0                         /* aci */
#define ACI_SUBSCR_PROTO_MAIL               1                        /* mail */
#define ACI_SUBSCR_PROTO_SERVER             2                      /* server */
#define ACI_SUBSCR_PROTO_HTTP               3                        /* http */
#define ACI_SUBSCR_PROTO_MAX                4       /* max current protocols */

/*------------- Supported Values for presentation for recepient -------------*/
#define ACI_SUBSCR_PRES_DEFAULT             0                     /* default */
#define ACI_SUBSCR_PRES_XML                 1                         /* xml */
#define ACI_SUBSCR_PRES_MAX                 2   /* max current presentations */

/*------------- Supported QOS values for notification registrations ---------*/
#define ACI_SUBSCR_QOS_RELIABLE             0x01                 /* reliable */
#define ACI_SUBSCR_QOS_PAYLOAD              0x02         /* payload delivery */
#define ACI_SUBSCR_QOS_REPLICATE            0x04    /* replicate to director */
#define ACI_SUBSCR_QOS_SECURE               0x08  /* secure payload delivery */
#define ACI_SUBSCR_QOS_PURGE_ON_NTFN        0x10      /* purge on first ntfn */
#define ACI_SUBSCR_QOS_MULTICBK             0x20  /* multi instance callback */

/* ----- Temporary attribute value for UCS2/UTF16 character set ID -------- */ 
#define ACI_UCS2ID            1000                        /* UCS2 charset ID */
#define ACI_UTF16ID           1000                       /* UTF16 charset ID */

/*============================== End ACI Attribute Types ====================*/

/*---------------- Server Handle Attribute Values ---------------------------*/

/* ACI_ATTR_SERVER_STATUS */
#define ACI_SERVER_NOT_CONNECTED        0x0 
#define ACI_SERVER_NORMAL               0x1 

/*---------------------------------------------------------------------------*/

/*------------------------- Supported Namespaces  ---------------------------*/
#define ACI_SUBSCR_NAMESPACE_ANONYMOUS   0            /* Anonymous Namespace */
#define ACI_SUBSCR_NAMESPACE_AQ          1                /* Advanced Queues */
#define ACI_SUBSCR_NAMESPACE_DBCHANGE    2            /* change notification */
#define ACI_SUBSCR_NAMESPACE_MAX         3          /* Max Name Space Number */

//神通目前支持的text类型最大长度为64000,KStore支持的最大长度为150000
//为同时兼容两个后台,且在不修改协议的情况下，将此宏按照较大值定义
#define ACI_TEXT_MAX_LEN      150000L 

/*-------------------------Credential Types----------------------------------*/
#define ACI_CRED_RDBMS      1                  /* database username/password */
#define ACI_CRED_EXT        2             /* externally provided credentials */
#define ACI_CRED_PROXY      3                        /* proxy authentication */
#define ACI_CRED_RESERVED_1 4                                    /* reserved */
#define ACI_CRED_RESERVED_2 5                                    /* reserved */
/*---------------------------------------------------------------------------*/

/*------------------------Error Return Values--------------------------------*/
#define ACI_SUCCESS 0                      /* maps to SQL_SUCCESS of SAG CLI */
#define ACI_SUCCESS_WITH_INFO 1             /* maps to SQL_SUCCESS_WITH_INFO */
#define ACI_RESERVED_FOR_INT_USE 200                            /* reserved */ 
#define ACI_NO_DATA 100                               /* maps to SQL_NO_DATA */
#define ACI_ERROR -1                                    /* maps to SQL_ERROR */
#define ACI_INVALID_HANDLE -2                  /* maps to SQL_INVALID_HANDLE */
#define ACI_NEED_DATA 99                            /* maps to SQL_NEED_DATA */
#define ACI_STILL_EXECUTING -3123                   /* ACI would block error */
/*---------------------------------------------------------------------------*/

/*--------------------- User Callback Return Values -------------------------*/
#define ACI_CONTINUE -24200    /* Continue with the body of the ACI function */
#define ACI_ROWCBK_DONE   -24201              /* done with user row callback */
/*---------------------------------------------------------------------------*/

/*------------------DateTime and Interval check Error codes------------------*/

/* DateTime Error Codes used by ACIDateTimeCheck() */
#define   ACI_DT_INVALID_DAY         0x1                          /* Bad day */
#define   ACI_DT_DAY_BELOW_VALID     0x2      /* Bad DAy Low/high bit (1=low)*/
#define   ACI_DT_INVALID_MONTH       0x4                       /*  Bad MOnth */
#define   ACI_DT_MONTH_BELOW_VALID   0x8   /* Bad MOnth Low/high bit (1=low) */
#define   ACI_DT_INVALID_YEAR        0x10                        /* Bad YeaR */
#define   ACI_DT_YEAR_BELOW_VALID    0x20  /*  Bad YeaR Low/high bit (1=low) */
#define   ACI_DT_INVALID_HOUR        0x40                       /*  Bad HouR */
#define   ACI_DT_HOUR_BELOW_VALID    0x80   /* Bad HouR Low/high bit (1=low) */
#define   ACI_DT_INVALID_MINUTE      0x100                     /* Bad MiNute */
#define   ACI_DT_MINUTE_BELOW_VALID  0x200 /*Bad MiNute Low/high bit (1=low) */
#define   ACI_DT_INVALID_SECOND      0x400                    /*  Bad SeCond */
#define   ACI_DT_SECOND_BELOW_VALID  0x800  /*bad second Low/high bit (1=low)*/
#define   ACI_DT_DAY_MISSING_FROM_1582 0x1000     
                                 /*  Day is one of those "missing" from 1582 */
#define   ACI_DT_YEAR_ZERO           0x2000       /* Year may not equal zero */
#define   ACI_DT_INVALID_TIMEZONE    0x4000                 /*  Bad Timezone */
#define   ACI_DT_INVALID_FORMAT      0x8000         /* Bad date format input */


/* Interval Error Codes used by ACIInterCheck() */
#define   ACI_INTER_INVALID_DAY         0x1                       /* Bad day */
#define   ACI_INTER_DAY_BELOW_VALID     0x2  /* Bad DAy Low/high bit (1=low) */
#define   ACI_INTER_INVALID_MONTH       0x4                     /* Bad MOnth */
#define   ACI_INTER_MONTH_BELOW_VALID   0x8 /*Bad MOnth Low/high bit (1=low) */
#define   ACI_INTER_INVALID_YEAR        0x10                     /* Bad YeaR */
#define   ACI_INTER_YEAR_BELOW_VALID    0x20 /*Bad YeaR Low/high bit (1=low) */
#define   ACI_INTER_INVALID_HOUR        0x40                     /* Bad HouR */
#define   ACI_INTER_HOUR_BELOW_VALID    0x80 /*Bad HouR Low/high bit (1=low) */
#define   ACI_INTER_INVALID_MINUTE      0x100                  /* Bad MiNute */
#define   ACI_INTER_MINUTE_BELOW_VALID  0x200 
                                            /*Bad MiNute Low/high bit(1=low) */
#define   ACI_INTER_INVALID_SECOND      0x400                  /* Bad SeCond */
#define   ACI_INTER_SECOND_BELOW_VALID  0x800   
                                            /*bad second Low/high bit(1=low) */
#define   ACI_INTER_INVALID_FRACSEC     0x1000      /* Bad Fractional second */
#define   ACI_INTER_FRACSEC_BELOW_VALID 0x2000  
                                           /* Bad fractional second Low/High */


/*------------------------Parsing Syntax Types-------------------------------*/
#define ACI_V7_SYNTAX 2       /* V815 language - for backwards compatibility */
#define ACI_V8_SYNTAX 3       /* V815 language - for backwards compatibility */
#define ACI_NTV_SYNTAX 1    /* Use what so ever is the native lang of server */
                     /* these values must match the values defined in kpul.h */
/*---------------------------------------------------------------------------*/

/*------------------------(Scrollable Cursor) Fetch Options------------------- 
 * For non-scrollable cursor, the only valid (and default) orientation is 
 * ACI_FETCH_NEXT
 */
#define ACI_FETCH_CURRENT    0x00000001      /* refetching current position  */
#define ACI_FETCH_NEXT       0x00000002                          /* next row */
#define ACI_FETCH_FIRST      0x00000004       /* first row of the result set */
#define ACI_FETCH_LAST       0x00000008    /* the last row of the result set */
#define ACI_FETCH_PRIOR      0x00000010  /* previous row relative to current */
#define ACI_FETCH_ABSOLUTE   0x00000020        /* absolute offset from first */
#define ACI_FETCH_RELATIVE   0x00000040        /* offset relative to current */
#define ACI_FETCH_RESERVED_1 0x00000080                          /* reserved */
#define ACI_FETCH_RESERVED_2 0x00000100                          /* reserved */
#define ACI_FETCH_RESERVED_3 0x00000200                          /* reserved */
#define ACI_FETCH_RESERVED_4 0x00000400                          /* reserved */
#define ACI_FETCH_RESERVED_5 0x00000800                          /* reserved */

/*---------------------------------------------------------------------------*/

/*------------------------Bind and Define Options----------------------------*/
#define ACI_SB2_IND_PTR       0x00000001                           /* unused */
#define ACI_DATA_AT_EXEC      0x00000002             /* data at execute time */
#define ACI_DYNAMIC_FETCH     0x00000002                /* fetch dynamically */
#define ACI_PIECEWISE         0x00000004          /* piecewise DMLs or fetch */
#define ACI_DEFINE_RESERVED_1 0x00000008                         /* reserved */
#define ACI_BIND_RESERVED_2   0x00000010                         /* reserved */
#define ACI_DEFINE_RESERVED_2 0x00000020                         /* reserved */
#define ACI_BIND_SOFT         0x00000040              /* soft bind or define */
#define ACI_DEFINE_SOFT       0x00000080              /* soft bind or define */
#define ACI_BIND_RESERVED_3   0x00000100                         /* reserved */
/*---------------------------------------------------------------------------*/

/*-----------------------------  Various Modes ------------------------------*/
#define ACI_DEFAULT         0x00000000 
                          /* the default value for parameters and attributes */
/*-------------ACIInitialize Modes / ACICreateEnvironment Modes -------------*/
#define ACI_THREADED        0x00000001      /* appl. in threaded environment */
#define ACI_OBJECT          0x00000002  /* application in object environment */
#define ACI_EVENTS          0x00000004  /* application is enabled for events */
#define ACI_RESERVED1       0x00000008                           /* reserved */
#define ACI_SHARED          0x00000010  /* the application is in shared mode */
#define ACI_RESERVED2       0x00000020                           /* reserved */
/* The following *TWO* are only valid for ACICreateEnvironment call */
#define ACI_NO_UCB          0x00000040 /* No user callback called during ini */
#define ACI_NO_MUTEX        0x00000080 /* the environment handle will not be */
                                         /*  protected by a mutex internally */
#define ACI_SHARED_EXT      0x00000100              /* Used for shared forms */
/************************** 0x00000200 free **********************************/
#define ACI_ALWAYS_BLOCKING 0x00000400    /* all connections always blocking */
/************************** 0x00000800 free **********************************/
#define ACI_USE_LDAP        0x00001000            /* allow  LDAP connections */
#define ACI_REG_LDAPONLY    0x00002000              /* only register to LDAP */
#define ACI_UTF16           0x00004000        /* mode for all UTF16 metadata */
#define ACI_AFC_PAD_ON      0x00008000 
                             /* turn on AFC blank padding when rlenp present */
#define ACI_ENVCR_RESERVED3 0x00010000                           /* reserved */
#define ACI_NEW_LENGTH_SEMANTICS  0x00020000   /* adopt new length semantics */
       /* the new length semantics, always bytes, is used by ACIEnvNlsCreate */
#define ACI_NO_MUTEX_STMT   0x00040000           /* Do not mutex stmt handle */
#define ACI_MUTEX_ENV_ONLY  0x00080000  /* Mutex only the environment handle */
#define ACI_STM_RESERVED4   0x00100000                           /* reserved */
#define ACI_MUTEX_TRY       0x00200000              /* try and acquire mutex */
#define ACI_NCHAR_LITERAL_REPLACE_ON  0x00400000 /* nchar literal replace on */
#define ACI_NCHAR_LITERAL_REPLACE_OFF 0x00800000 /* nchar literal replace off*/
#define ACI_SRVATCH_RESERVED5 0x01000000                         /* reserved */
#define ACI_INPUTVLD_CONNSTR_ATTR 0x02000000	/* tempdef for OCIInputValidate() */



/*---------------------------------------------------------------------------*/
/*------------------------ACIConnectionpoolCreate Modes----------------------*/

#define ACI_CPOOL_REINITIALIZE 0x111

/*---------------------------------------------------------------------------*/
/*--------------------------------- ACILogon2 Modes -------------------------*/

#define ACI_LOGON2_SPOOL       0x0001     /* Use session pool */
#define ACI_LOGON2_CPOOL       ACI_CPOOL  /* Use connection pool */
#define ACI_LOGON2_STMTCACHE   0x0004     /* Use Stmt Caching */
#define ACI_LOGON2_PROXY       0x0008     /* Proxy authentiaction */

/*---------------------------------------------------------------------------*/
/*------------------------- ACISessionPoolCreate Modes ----------------------*/

#define ACI_SPC_REINITIALIZE 0x0001   /* Reinitialize the session pool */
#define ACI_SPC_HOMOGENEOUS  0x0002   /* Session pool is homogeneneous */
#define ACI_SPC_STMTCACHE    0x0004   /* Session pool has stmt cache */
#define ACI_SPC_NO_RLB		 0x0008

/*---------------------------------------------------------------------------*/
/*--------------------------- ACISessionGet Modes ---------------------------*/

#define ACI_SESSGET_SPOOL      0x0001     /* SessionGet called in SPOOL mode */
#define ACI_SESSGET_STMTCACHE  0x0004                 /* Use statement cache */
#define ACI_SESSGET_CREDPROXY  0x0008     /* SessionGet called in proxy mode */
#define ACI_SESSGET_CREDEXT    0x0010     
#define ACI_SESSGET_SPOOL_MATCHANY 0x0020
#define ACI_SESSGET_PURITY_NEW     0x0040 
#define ACI_SESSGET_PURITY_SELF    0x0080 
#define ACI_SESSGET_SYSDBA    0x0100    /* SessionGet with SYSDBA privileges */
#define ACI_SESSGET_CPOOL     0x0200      /* SessionGet called in CPOOL mode */
#define ACI_SESSGET_MULTIPROPERTY_TAG 0x0400           /* multi property tag */
#define ACI_SESSGET_CUSTOM_POOL       0x0800             /* Custom Pool Mode */

/*---------------------------------------------------------------------------*/
/*------------------- OCI_ATTR_SESSGET_FLAGS values -------------------------*/
#define ACI_SESSGET_FLAGS_NEW           0x0001             /* new connection */
#define ACI_SESSGET_FLAGS_POOLED_SERVER 0x0002   /* pooled server connection */
#define ACI_SESSGET_FLAGS_SHARD  0x0004  /* connected to shard in sharded DB */
#define ACI_SESSGET_FLAGS_RAC_DATA_AFFN 0x0008      /* connected to RAC Data
                                                   Affinity enabled database */

/*---------------------------------------------------------------------------*/
/*------------------------ATTR Values for Session Pool-----------------------*/
/* Attribute values for ACI_ATTR_SPOOL_GETMODE */
#define ACI_SPOOL_ATTRVAL_WAIT		0			/* block till you get a session */
#define ACI_SPOOL_ATTRVAL_NOWAIT	1			/* error out if no session avaliable */
#define ACI_SPOOL_ATTRVAL_FORCEGET	2			/* get session even if max is exceeded */
#define ACI_SPOOL_ATTRVAL_TIMEDWAIT 3			/* wait for specified timeout if pool
												 * is maxed out                       */

/*---------------------------------------------------------------------------*/
/*--------------------------- ACISessionRelease Modes -----------------------*/

#define ACI_SESSRLS_DROPSESS			 0x0001        /* Drop the Session */
#define ACI_SESSRLS_RETAG				 0x0002        /* Retag the session */
#define ACI_SESSRLS_MULTIPROPERTY_TAG    0x0004        /* multi property tag */

/*---------------------------------------------------------------------------*/
/*----------------------- ACISessionPoolDestroy Modes -----------------------*/

#define ACI_SPD_FORCE        0x0001       /* Force the sessions to terminate. 
                                             Even if there are some busy 
                                             sessions close them */
#define ACI_SPD_DRAIN        0x0002 

 
/*---------------------------------------------------------------------------*/
/*----------------------------- Statement States ----------------------------*/

#define ACI_STMT_STATE_INITIALIZED  0x0001
#define ACI_STMT_STATE_EXECUTED     0x0002
#define ACI_STMT_STATE_END_OF_FETCH 0x0003

/*---------------------------------------------------------------------------*/

/*----------------------------- ACIMemStats Modes ---------------------------*/
#define ACI_MEM_INIT        0x01 
#define ACI_MEM_CLN         0x02 
#define ACI_MEM_FLUSH       0x04 
#define ACI_DUMP_HEAP       0x80

#define ACI_CLIENT_STATS    0x10 
#define ACI_SERVER_STATS    0x20 

/*----------------------------- ACIEnvInit Modes ----------------------------*/
/* NOTE: NO NEW MODES SHOULD BE ADDED HERE BECAUSE THE RECOMMENDED METHOD 
 * IS TO USE THE NEW ACICreateEnvironment MODES.
 */
#define ACI_ENV_NO_UCB 0x01         /* A user callback will not be called in
                                       ACIEnvInit() */
#define ACI_ENV_NO_MUTEX 0x08 /* the environment handle will not be protected
                                 by a mutex internally */

/*---------------------------------------------------------------------------*/

/*------------------------ Prepare Modes ------------------------------------*/
#define ACI_NO_SHARING        0x01      /* turn off statement handle sharing */
#define ACI_PREP_RESERVED_1   0x02                               /* reserved */
#define ACI_PREP_AFC_PAD_ON   0x04          /* turn on blank padding for AFC */
#define ACI_PREP_AFC_PAD_OFF  0x08         /* turn off blank padding for AFC */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/

/*----------------------- Execution Modes -----------------------------------*/
#define ACI_BATCH_MODE             0x00000001 /* batch the oci stmt for exec */
#define ACI_EXACT_FETCH            0x00000002  /* fetch exact rows specified */
/* #define                         0x00000004                      available */
#define ACI_STMT_SCROLLABLE_READONLY \
                                   0x00000008 /* if result set is scrollable */
#define ACI_DESCRIBE_ONLY          0x00000010 /* only describe the statement */
#define ACI_COMMIT_ON_SUCCESS      0x00000020  /* commit, if successful exec */
#define ACI_NON_BLOCKING           0x00000040                /* non-blocking */
#define ACI_BATCH_ERRORS           0x00000080  /* batch errors in array dmls */
#define ACI_PARSE_ONLY             0x00000100    /* only parse the statement */
#define ACI_EXACT_FETCH_RESERVED_1 0x00000200                    /* reserved */
#define ACI_SHOW_DML_WARNINGS      0x00000400   
		 /* return ACI_SUCCESS_WITH_INFO for delete/update w/no where clause */
#define ACI_EXEC_RESERVED_2        0x00000800                    /* reserved */
#define ACI_DESC_RESERVED_1        0x00001000                    /* reserved */
#define ACI_EXEC_RESERVED_3        0x00002000                    /* reserved */
#define ACI_EXEC_RESERVED_4        0x00004000                    /* reserved */
#define ACI_EXEC_RESERVED_5        0x00008000                    /* reserved */
#define ACI_EXEC_RESERVED_6        0x00010000                    /* reserved */
#define ACI_RESULT_CACHE           0x00020000   /* hint to use query caching */
#define ACI_NO_RESULT_CACHE        0x00040000  /*hint to bypass query caching*/
#define ACI_EXEC_RESERVED_7        0x00080000                    /* reserved */
#define ACI_RETURN_ROW_COUNT_ARRAY 0x00100000 /* Per Iter DML Row Count mode */
/*---------------------------------------------------------------------------*/

/*------------------------Authentication Modes-------------------------------*/
#define ACI_MIGRATE         0x00000001            /* migratable auth context */
#define ACI_SYSDBA          0x00000002           /* for SYSDBA authorization */
#define ACI_SYSOPER         0x00000004          /* for SYSOPER authorization */
#define ACI_PRELIM_AUTH     0x00000008      /* for preliminary authorization */
#define ACIP_ICACHE         0x00000010             /* Private ACI cache mode */
#define ACI_AUTH_RESERVED_1 0x00000020                           /* reserved */
#define ACI_STMT_CACHE      0x00000040            /* enable ACI Stmt Caching */
#define ACI_STATELESS_CALL  0x00000080         /* stateless at call boundary */
#define ACI_STATELESS_TXN   0x00000100          /* stateless at txn boundary */
#define ACI_STATELESS_APP   0x00000200    /* stateless at user-specified pts */
#define ACI_AUTH_RESERVED_2 0x00000400                           /* reserved */
#define ACI_AUTH_RESERVED_3 0x00000800                           /* reserved */
#define ACI_AUTH_RESERVED_4 0x00001000                           /* reserved */
#define ACI_AUTH_RESERVED_5 0x00002000                           /* reserved */

/*---------------------------------------------------------------------------*/

/*------------------------Session End Modes----------------------------------*/
#define ACI_SESSEND_RESERVED_1 0x0001                            /* reserved */
#define ACI_SESSEND_RESERVED_2 0x0002                            /* reserved */
/*---------------------------------------------------------------------------*/

/*------------------------Attach Modes---------------------------------------*/

/* The following attach modes are the same as the UPI modes defined in 
 * UPIDEF.H.  Do not use these values externally.
 */

#define ACI_FASTPATH         0x0010              /* Attach in fast path mode */
#define ACI_ATCH_RESERVED_1  0x0020                              /* reserved */
#define ACI_ATCH_RESERVED_2  0x0080                              /* reserved */
#define ACI_ATCH_RESERVED_3  0x0100                              /* reserved */
#define ACI_CPOOL            0x0200  /* Attach using server handle from pool */
#define ACI_ATCH_RESERVED_4  0x0400                              /* reserved */
#define ACI_ATCH_RESERVED_5  0x2000                              /* reserved */

/*---------------------ACIStmtPrepare2 Modes---------------------------------*/
#define ACI_PREP2_CACHE_SEARCHONLY    0x0010                  /* ONly Search */
#define ACI_PREP2_GET_PLSQL_WARNINGS  0x0020         /* Get PL/SQL warnings  */
#define ACI_PREP2_RESERVED_1          0x0040                     /* reserved */
#define ACI_PREP2_RESERVED_2          0x0080                     /* reserved */
#define ACI_PREP2_RESERVED_3          0x0100                     /* reserved */
#define ACI_PREP2_RESERVED_4          0x0200                     /* reserved */
#define ACI_PREP2_IMPL_RESULTS_CLIENT 0x0400  /* client for implicit results */
#define ACI_PREP2_RESERVED_5          0x0800                     /* reserved */
#define ACI_PREP2_RESERVED_6          0x1000                     /* reserved */
#define ACI_PREP2_GET_SQL_ID          0x2000  /* Get SQL_ID for the SQL stmt */
#define ACI_PREP2_RESERVED_7          0x4000                     /* reserved */
#define ACI_PREP2_RESERVED_8          0x8000                     /* reserved */
#define ACI_PREP2_RESERVED_9          0x10000                    /* reserved */

/*---------------------ACIStmtRelease Modes----------------------------------*/
#define ACI_STRLS_CACHE_DELETE      0x0010              /* Delete from Cache */

/*-----------------------------End Various Modes ----------------------------*/

/*------------------------Piece Information----------------------------------*/
#define ACI_PARAM_IN 0x01                                    /* in parameter */
#define ACI_PARAM_OUT 0x02                                  /* out parameter */
/*---------------------------------------------------------------------------*/

/*------------------------ Transaction Start Flags --------------------------*/
/* NOTE: ACI_TRANS_JOIN and ACI_TRANS_NOMIGRATE not supported in 8.0.X       */
#define ACI_TRANS_NEW          0x00000001 /* starts a new transaction branch */
#define ACI_TRANS_JOIN         0x00000002    /* join an existing transaction */
#define ACI_TRANS_RESUME       0x00000004         /* resume this transaction */
#define ACI_TRANS_STARTMASK    0x000000ff

#define ACI_TRANS_READONLY     0x00000100   /* starts a readonly transaction */
#define ACI_TRANS_READWRITE    0x00000200 /* starts a read-write transaction */
#define ACI_TRANS_SERIALIZABLE 0x00000400
                                        /* starts a serializable transaction */
#define ACI_TRANS_ISOLMASK     0x0000ff00

#define ACI_TRANS_LOOSE        0x00010000        /* a loosely coupled branch */
#define ACI_TRANS_TIGHT        0x00020000        /* a tightly coupled branch */
#define ACI_TRANS_TYPEMASK     0x000f0000

#define ACI_TRANS_NOMIGRATE    0x00100000      /* non migratable transaction */
#define ACI_TRANS_SEPARABLE    0x00200000  /* separable transaction (8.1.6+) */
#define ACI_TRANS_OTSRESUME    0x00400000      /* OTS resuming a transaction */


/*---------------------------------------------------------------------------*/

/*------------------------ Transaction End Flags ----------------------------*/
#define ACI_TRANS_TWOPHASE      0x01000000           /* use two phase commit */
#define ACI_TRANS_WRITEBATCH    0x00000001  /* force cmt-redo for local txns */
#define ACI_TRANS_WRITEIMMED    0x00000002              /* no force cmt-redo */
#define ACI_TRANS_WRITEWAIT     0x00000004               /* no sync cmt-redo */
#define ACI_TRANS_WRITENOWAIT   0x00000008   /* sync cmt-redo for local txns */
/*---------------------------------------------------------------------------*/

/*------------------------- AQ Constants ------------------------------------
 * NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE
 * The following constants must match the PL/SQL dbms_aq constants
 * NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE
 */
/* ------------------------- Visibility flags -------------------------------*/
#define ACI_ENQ_IMMEDIATE       1   /* enqueue is an independent transaction */
#define ACI_ENQ_ON_COMMIT       2  /* enqueue is part of current transaction */

/* ----------------------- Dequeue mode flags -------------------------------*/
#define ACI_DEQ_BROWSE          1   /* read message without acquiring a lock */
#define ACI_DEQ_LOCKED          2   /* read and obtain write lock on message */
#define ACI_DEQ_REMOVE          3          /* read the message and delete it */
#define ACI_DEQ_REMOVE_NODATA   4    /* delete message w'o returning payload */
#define ACI_DEQ_GETSIG          5                      /* get signature only */

/* ----------------- Dequeue navigation flags -------------------------------*/
#define ACI_DEQ_FIRST_MSG        1     /* get first message at head of queue */
#define ACI_DEQ_NEXT_MSG         3         /* next message that is available */
#define ACI_DEQ_NEXT_TRANSACTION 2    /* get first message of next txn group */
#define ACI_DEQ_MULT_TRANSACTION 5        /* array dequeue across txn groups */

/* ----------------- Dequeue Option Reserved flags ------------------------- */
#define ACI_DEQ_RESERVED_1      0x000001

/* --------------------- Message states -------------------------------------*/
#define ACI_MSG_WAITING         1 /* the message delay has not yet completed */
#define ACI_MSG_READY           0    /* the message is ready to be processed */
#define ACI_MSG_PROCESSED       2          /* the message has been processed */
#define ACI_MSG_EXPIRED         3    /* message has moved to exception queue */

/* --------------------- Sequence deviation ---------------------------------*/
#define ACI_ENQ_BEFORE          2  /* enqueue message before another message */
#define ACI_ENQ_TOP             3     /* enqueue message before all messages */

/* ------------------------- Visibility flags -------------------------------*/
#define ACI_DEQ_IMMEDIATE       1   /* dequeue is an independent transaction */
#define ACI_DEQ_ON_COMMIT       2  /* dequeue is part of current transaction */

/* ------------------------ Wait --------------------------------------------*/
#define ACI_DEQ_WAIT_FOREVER    -1   /* wait forever if no message available */
#define ACI_DEQ_NO_WAIT         0  /* do not wait if no message is available */

/* ------------------------ Delay -------------------------------------------*/
#define ACI_MSG_NO_DELAY        0        /* message is available immediately */

/* ------------------------- Expiration -------------------------------------*/
#define ACI_MSG_NO_EXPIRATION -1                /* message will never expire */

#define ACI_MSG_PERSISTENT_OR_BUFFERED   3
#define ACI_MSG_BUFFERED                 2
#define ACI_MSG_PERSISTENT               1

/* -------------------------- for OCIAQEnq() --------------------------------*/
#define ACI_AQ_PERSISTENT					1
#define ACI_AQ_BUFFERED						2

/* ------------------------- Reserved ---------------------------------------*/
#define ACI_AQ_RESERVED_1      0x0002
#define ACI_AQ_RESERVED_2      0x0004
#define ACI_AQ_RESERVED_3      0x0008
#define ACI_AQ_RESERVED_4      0x0010

/* -------------------------- END AQ Constants ----------------------------- */

/* --------------------END DateTime and Interval Constants ------------------*/

/*-----------------------Object Types----------------------------------------*/
/*-----------Object Types **** Not to be Used **** --------------------------*/
/* Deprecated */
#define ACI_OTYPE_UNK           0
#define ACI_OTYPE_TABLE         1
#define ACI_OTYPE_VIEW          2
#define ACI_OTYPE_SYN           3
#define ACI_OTYPE_PROC          4
#define ACI_OTYPE_FUNC          5
#define ACI_OTYPE_PKG           6
#define ACI_OTYPE_STMT          7
/*---------------------------------------------------------------------------*/

/*=======================Describe Handle Parameter Attributes ===============*/
/* 
   These attributes are orthogonal to the other set of attributes defined 
   above.  These attrubutes are to be used only for the describe handle. 
*/
/*===========================================================================*/
/* Attributes common to Columns and Stored Procs */
#define ACI_ATTR_DATA_SIZE      1                /* maximum size of the data */
#define ACI_ATTR_DATA_TYPE      2     /* the SQL type of the column/argument */
#define ACI_ATTR_DISP_SIZE      3                        /* the display size */
#define ACI_ATTR_NAME           4         /* the name of the column/argument */
#define ACI_ATTR_PRECISION      5                /* precision if number type */
#define ACI_ATTR_SCALE          6                    /* scale if number type */
#define ACI_ATTR_IS_NULL        7                            /* is it null ? */
#define ACI_ATTR_TYPE_NAME      8
  /* name of the named data type or a package name for package private types */
#define ACI_ATTR_SCHEMA_NAME    9             /* the schema name */
#define ACI_ATTR_SUB_NAME       10      /* type name if package private type */
#define ACI_ATTR_POSITION       11
                    /* relative position of col/arg in the list of cols/args */
#define ACI_ATTR_PACKAGE_NAME   12           /* package name of package type */
#define ACI_ATTR_REFERENCED     13        /* column is referenced (reserved) */
/*---------------------------End Describe Handle Attributes -----------------*/
#define ACI_ATTR_SER_TYPE       12      /* the ST type of the column/argument */
/* complex object retrieval parameter attributes */
#define ACI_ATTR_COMPLEXOBJECTCOMP_TYPE         50 
#define ACI_ATTR_COMPLEXOBJECTCOMP_TYPE_LEVEL   51
#define ACI_ATTR_COMPLEXOBJECT_LEVEL            52
#define ACI_ATTR_COMPLEXOBJECT_COLL_OUTOFLINE   53

/* Only Columns */
#define ACI_ATTR_DISP_NAME      100                      /* the display name */
#define ACI_ATTR_ENCC_SIZE      101                   /* encrypted data size */
#define ACI_ATTR_COL_ENC        102                 /* column is encrypted ? */
#define ACI_ATTR_COL_ENC_SALT   103          /* is encrypted column salted ? */

/*Only Stored Procs */
#define ACI_ATTR_OVERLOAD       210           /* is this position overloaded */
#define ACI_ATTR_LEVEL          211            /* level for structured types */
#define ACI_ATTR_HAS_DEFAULT    212                   /* has a default value */
#define ACI_ATTR_IOMODE         213                         /* in, out inout */
#define ACI_ATTR_RADIX          214                       /* returns a radix */
#define ACI_ATTR_NUM_ARGS       215             /* total number of arguments */

/* only named type attributes */
#define ACI_ATTR_TYPECODE                  216       /* object or collection */
#define ACI_ATTR_COLLECTION_TYPECODE       217     /* varray or nested table */
#define ACI_ATTR_VERSION                   218      /* user assigned version */
#define ACI_ATTR_IS_INCOMPLETE_TYPE        219 /* is this an incomplete type */
#define ACI_ATTR_IS_SYSTEM_TYPE            220              /* a system type */
#define ACI_ATTR_IS_PREDEFINED_TYPE        221          /* a predefined type */
#define ACI_ATTR_IS_TRANSIENT_TYPE         222           /* a transient type */
#define ACI_ATTR_IS_SYSTEM_GENERATED_TYPE  223      /* system generated type */
#define ACI_ATTR_HAS_NESTED_TABLE          224 /* contains nested table attr */
#define ACI_ATTR_HAS_LOB                   225        /* has a lob attribute */
#define ACI_ATTR_HAS_FILE                  226       /* has a file attribute */
#define ACI_ATTR_COLLECTION_ELEMENT        227 /* has a collection attribute */
#define ACI_ATTR_NUM_TYPE_ATTRS            228  /* number of attribute types */
#define ACI_ATTR_LIST_TYPE_ATTRS           229    /* list of type attributes */
#define ACI_ATTR_NUM_TYPE_METHODS          230     /* number of type methods */
#define ACI_ATTR_LIST_TYPE_METHODS         231       /* list of type methods */
#define ACI_ATTR_MAP_METHOD                232         /* map method of type */
#define ACI_ATTR_ORDER_METHOD              233       /* order method of type */

/* only collection element */
#define ACI_ATTR_NUM_ELEMS                 234         /* number of elements */

/* only type methods */
#define ACI_ATTR_ENCAPSULATION             235        /* encapsulation level */
#define ACI_ATTR_IS_SELFISH                236             /* method selfish */
#define ACI_ATTR_IS_VIRTUAL                237                    /* virtual */
#define ACI_ATTR_IS_INLINE                 238                     /* inline */
#define ACI_ATTR_IS_CONSTANT               239                   /* constant */
#define ACI_ATTR_HAS_RESULT                240                 /* has result */
#define ACI_ATTR_IS_CONSTRUCTOR            241                /* constructor */
#define ACI_ATTR_IS_DESTRUCTOR             242                 /* destructor */
#define ACI_ATTR_IS_OPERATOR               243                   /* operator */
#define ACI_ATTR_IS_MAP                    244               /* a map method */
#define ACI_ATTR_IS_ORDER                  245               /* order method */
#define ACI_ATTR_IS_RNDS                   246  /* read no data state method */
#define ACI_ATTR_IS_RNPS                   247      /* read no process state */
#define ACI_ATTR_IS_WNDS                   248 /* write no data state method */
#define ACI_ATTR_IS_WNPS                   249     /* write no process state */

#define ACI_ATTR_DESC_PUBLIC               250              /* public object */

/* Object Cache Enhancements : attributes for User Constructed Instances     */
#define ACI_ATTR_CACHE_CLIENT_CONTEXT      251
#define ACI_ATTR_UCI_CONSTRUCT             252
#define ACI_ATTR_UCI_DESTRUCT              253
#define ACI_ATTR_UCI_COPY                  254
#define ACI_ATTR_UCI_PICKLE                255
#define ACI_ATTR_UCI_UNPICKLE              256
#define ACI_ATTR_UCI_REFRESH               257

/* for type inheritance */
#define ACI_ATTR_IS_SUBTYPE                258
#define ACI_ATTR_SUPERTYPE_SCHEMA_NAME     259
#define ACI_ATTR_SUPERTYPE_NAME            260

/* for schemas */
#define ACI_ATTR_LIST_OBJECTS              261  /* list of objects in schema */

/* for database */
#define ACI_ATTR_NCHARSET_ID               262                /* char set id */
#define ACI_ATTR_LIST_SCHEMAS              263            /* list of schemas */
#define ACI_ATTR_MAX_PROC_LEN              264       /* max procedure length */
#define ACI_ATTR_MAX_COLUMN_LEN            265     /* max column name length */
#define ACI_ATTR_CURSOR_COMMIT_BEHAVIOR    266     /* cursor commit behavior */
#define ACI_ATTR_MAX_CATALOG_NAMELEN       267         /* catalog namelength */
#define ACI_ATTR_CATALOG_LOCATION          268           /* catalog location */
#define ACI_ATTR_SAVEPOINT_SUPPORT         269          /* savepoint support */
#define ACI_ATTR_NOWAIT_SUPPORT            270             /* nowait support */
#define ACI_ATTR_AUTOCOMMIT_DDL            271             /* autocommit DDL */
#define ACI_ATTR_LOCKING_MODE              272               /* locking mode */

/* for externally initialized context */
#define ACI_ATTR_APPCTX_SIZE               273 /* count of context to be init*/
#define ACI_ATTR_APPCTX_LIST               274 /* count of context to be init*/
#define ACI_ATTR_APPCTX_NAME               275 /* name  of context to be init*/
#define ACI_ATTR_APPCTX_ATTR               276 /* attr  of context to be init*/
#define ACI_ATTR_APPCTX_VALUE              277 /* value of context to be init*/

/* for client id propagation */
#define ACI_ATTR_CLIENT_IDENTIFIER         278   /* value of client id to set*/

/* for inheritance - part 2 */
#define ACI_ATTR_IS_FINAL_TYPE             279            /* is final type ? */
#define ACI_ATTR_IS_INSTANTIABLE_TYPE      280     /* is instantiable type ? */
#define ACI_ATTR_IS_FINAL_METHOD           281          /* is final method ? */
#define ACI_ATTR_IS_INSTANTIABLE_METHOD    282   /* is instantiable method ? */
#define ACI_ATTR_IS_OVERRIDING_METHOD      283     /* is overriding method ? */

#define ACI_ATTR_DESC_SYNBASE              284   /* Describe the base object */


#define ACI_ATTR_CHAR_USED                 285      /* char length semantics */
#define ACI_ATTR_CHAR_SIZE                 286                /* char length */

/* SQLJ support */
#define ACI_ATTR_IS_JAVA_TYPE              287 /* is java implemented type ? */

/* N-Tier support */
#define ACI_ATTR_DISTINGUISHED_NAME        300        /* use DN as user name */
#define ACI_ATTR_KERBEROS_TICKET           301   /* Kerberos ticket as cred. */
 
/* for multilanguage debugging */
#define ACI_ATTR_ST_DEBUG_JDWP            302   /* ST_DEBUG_JDWP attribute */

#define ACI_ATTR_RESERVED_14               303                   /* reserved */


/*---------------------------End Describe Handle Attributes -----------------*/

/* For values 303 - 307, see DirPathAPI attribute section in this file */

/* ----------------------- Session Pool Attributes ------------------------- */
#define ACI_ATTR_ACCESS_BANNER             307              /* access banner */
#define ACI_ATTR_AUDIT_BANNER              308               /* audit banner */
#define ACI_ATTR_SPOOL_TIMEOUT              308           /* session timeout */
#define ACI_ATTR_SPOOL_GETMODE              309          /* session get mode */
#define ACI_ATTR_SPOOL_BUSY_COUNT           310        /* busy session count */
#define ACI_ATTR_SPOOL_OPEN_COUNT           311        /* open session count */
#define ACI_ATTR_SPOOL_MIN                  312         /* min session count */
#define ACI_ATTR_SPOOL_MAX                  313         /* max session count */
#define ACI_ATTR_SPOOL_INCR                 314   /* session increment count */
#define ACI_ATTR_SPOOL_STMTCACHESIZE        208   /*Stmt cache size of pool  */
/*------------------------------End Session Pool Attributes -----------------*/
/*---------------------------- For XML Types ------------------------------- */
/* For table, view and column */
#define ACI_ATTR_IS_XMLTYPE          315         /* Is the type an XML type? */
#define ACI_ATTR_XMLSCHEMA_NAME      316               /* Name of XML Schema */
#define ACI_ATTR_XMLELEMENT_NAME     317              /* Name of XML Element */
#define ACI_ATTR_XMLSQLTYPSCH_NAME   318    /* SQL type's schema for XML Ele */
#define ACI_ATTR_XMLSQLTYPE_NAME     319     /* Name of SQL type for XML Ele */
#define ACI_ATTR_XMLTYPE_STORED_OBJ  320       /* XML type stored as object? */

/*---------------------------- For Subtypes ------------------------------- */
/* For type */
#define ACI_ATTR_HAS_SUBTYPES        321                    /* Has subtypes? */
#define ACI_ATTR_NUM_SUBTYPES        322               /* Number of subtypes */
#define ACI_ATTR_LIST_SUBTYPES       323                 /* List of subtypes */

/* XML flag */
#define ACI_ATTR_XML_HRCHY_ENABLED   324               /* hierarchy enabled? */

/* Method flag */
#define ACI_ATTR_IS_OVERRIDDEN_METHOD 325           /* Method is overridden? */

/* For values 326 - 335, see DirPathAPI attribute section in this file */

/*------------- Attributes for 10i Distributed Objects ----------------------*/
#define ACI_ATTR_OBJ_SUBS                   336 /* obj col/tab substitutable */

/* For values 337 - 338, see DirPathAPI attribute section in this file */

/*---------- Attributes for 10i XADFIELD (NLS language, territory -----------*/
#define ACI_ATTR_XADFIELD_RESERVED_1        339                  /* reserved */
#define ACI_ATTR_XADFIELD_RESERVED_2        340                  /* reserved */
/*------------- Kerberos Secure Client Identifier ---------------------------*/
#define ACI_ATTR_KERBEROS_CID               341 /* Kerberos db service ticket*/


/*------------------------ Attributes for Rules objects ---------------------*/
#define ACI_ATTR_CONDITION                  342            /* rule condition */
#define ACI_ATTR_COMMENT                    343                   /* comment */
#define ACI_ATTR_VALUE                      344             /* Anydata value */
#define ACI_ATTR_EVAL_CONTEXT_OWNER         345        /* eval context owner */
#define ACI_ATTR_EVAL_CONTEXT_NAME          346         /* eval context name */
#define ACI_ATTR_EVALUATION_FUNCTION        347        /* eval function name */
#define ACI_ATTR_VAR_TYPE                   348             /* variable type */
#define ACI_ATTR_VAR_VALUE_FUNCTION         349   /* variable value function */
#define ACI_ATTR_VAR_METHOD_FUNCTION        350  /* variable method function */
#define ACI_ATTR_ACTION_CONTEXT             351            /* action context */
#define ACI_ATTR_LIST_TABLE_ALIASES         352     /* list of table aliases */
#define ACI_ATTR_LIST_VARIABLE_TYPES        353    /* list of variable types */
#define ACI_ATTR_TABLE_NAME                 356                /* table name */

/* For values 357 - 359, see DirPathAPI attribute section in this file */

#define ACI_ATTR_MESSAGE_CSCN               360              /* message cscn */
#define ACI_ATTR_MESSAGE_DSCN               361              /* message dscn */

/*--------------------- Audit Session ID ------------------------------------*/
#define ACI_ATTR_AUDIT_SESSION_ID           362          /* Audit session ID */

/*--------------------- Kerberos TGT Keys -----------------------------------*/
#define ACI_ATTR_KERBEROS_KEY               363  /* n-tier Kerberos cred key */
#define ACI_ATTR_KERBEROS_CID_KEY           364    /* SCID Kerberos cred key */


#define ACI_ATTR_TRANSACTION_NO             365         /* AQ enq txn number */

/*----------------------- Attributes for End To End Tracing -----------------*/
#define ACI_ATTR_MODULE                     366        /* module for tracing */
#define ACI_ATTR_ACTION                     367        /* action for tracing */
#define ACI_ATTR_CLIENT_INFO                368               /* client info */
#define ACI_ATTR_COLLECT_CALL_TIME          369         /* collect call time */
#define ACI_ATTR_CALL_TIME                  370         /* extract call time */
#define ACI_ATTR_ECONTEXT_ID                371      /* execution-id context */
#define ACI_ATTR_ECONTEXT_SEQ               372  /*execution-id sequence num */


/*------------------------------ Session attributes -------------------------*/
#define ACI_ATTR_SESSION_STATE              373             /* session state */
#define ACI_SESSION_STATELESS  1                             /* valid states */
#define ACI_SESSION_STATEFUL   2

#define ACI_ATTR_SESSION_STATETYPE          374        /* session state type */
#define ACI_SESSION_STATELESS_DEF  0                    /* valid state types */
#define ACI_SESSION_STATELESS_CAL  1
#define ACI_SESSION_STATELESS_TXN  2
#define ACI_SESSION_STATELESS_APP  3

#define ACI_ATTR_SESSION_STATE_CLEARED      376     /* session state cleared */
#define ACI_ATTR_SESSION_MIGRATED           377       /* did session migrate */
#define ACI_ATTR_SESSION_PRESERVE_STATE     388    /* preserve session state */

/* -------------------------- Admin Handle Attributes ---------------------- */

#define ACI_ATTR_ADMIN_PFILE                389    /* client-side param file */

/*----------------------- Attributes for End To End Tracing -----------------*/
/* -------------------------- HA Event Handle Attributes ------------------- */

#define ACI_ATTR_HOSTNAME         390                /* SYS_CONTEXT hostname */
#define ACI_ATTR_DBNAME           391                  /* SYS_CONTEXT dbname */
#define ACI_ATTR_INSTNAME         392           /* SYS_CONTEXT instance name */
#define ACI_ATTR_SERVICENAME      393            /* SYS_CONTEXT service name */
#define ACI_ATTR_INSTSTARTTIME    394      /* v$instance instance start time */
#define ACI_ATTR_HA_TIMESTAMP     395                          /* event time */
#define ACI_ATTR_RESERVED_22      396                            /* reserved */
#define ACI_ATTR_RESERVED_23      397                            /* reserved */
#define ACI_ATTR_RESERVED_24      398                            /* reserved */
#define ACI_ATTR_DBDOMAIN         399                           /* db domain */

#define ACI_ATTR_EVENTTYPE        400                          /* event type */
#define ACI_EVENTTYPE_HA            0  /* valid value for ACI_ATTR_EVENTTYPE */

#define ACI_ATTR_HA_SOURCE        401
/* valid values for ACI_ATTR_HA_SOURCE */
#define ACI_HA_SOURCE_INSTANCE            0 
#define ACI_HA_SOURCE_DATABASE            1
#define ACI_HA_SOURCE_NODE                2
#define ACI_HA_SOURCE_SERVICE             3
#define ACI_HA_SOURCE_SERVICE_MEMBER      4
#define ACI_HA_SOURCE_ASM_INSTANCE        5
#define ACI_HA_SOURCE_SERVICE_PRECONNECT  6

#define ACI_ATTR_HA_STATUS        402
#define ACI_HA_STATUS_DOWN          0 /* valid values for ACI_ATTR_HA_STATUS */
#define ACI_HA_STATUS_UP            1

#define ACI_ATTR_HA_SRVFIRST      403

#define ACI_ATTR_HA_SRVNEXT       404
/* ------------------------- Server Handle Attributes -----------------------*/

#define ACI_ATTR_TAF_ENABLED      405

/* Extra notification attributes */
#define ACI_ATTR_NFY_FLAGS        406 

#define ACI_ATTR_MSG_DELIVERY_MODE 407        /* msg delivery mode */
#define ACI_ATTR_DB_CHARSET_ID     416       /* database charset ID */
#define ACI_ATTR_DB_NCHARSET_ID    417       /* database ncharset ID */
#define ACI_ATTR_RESERVED_25       418                           /* reserved */

/*---------------------------------------------------------------------------*/
/* ------------------DirPathAPI attribute Section----------------------------*/
/* All DirPathAPI attributes are in this section of the file.  Existing      */
/* attributes prior to this section being created are assigned values < 2000 */
/* Add new DirPathAPI attributes to this section and their assigned value    */
/* should be whatever the last entry is + 1.                                 */

/*------------- Supported Values for Direct Path Stream Version -------------*/
#define ACI_DIRPATH_STREAM_VERSION_1        100
#define ACI_DIRPATH_STREAM_VERSION_2        200
#define ACI_DIRPATH_STREAM_VERSION_3        300                   /* default */


#define ACI_ATTR_DIRPATH_MODE           78  /* mode of direct path operation */
#define ACI_ATTR_DIRPATH_NOLOG          79               /* nologging option */
#define ACI_ATTR_DIRPATH_PARALLEL       80     /* parallel (temp seg) option */

#define ACI_ATTR_DIRPATH_SORTED_INDEX    137 /* index that data is sorted on */

            /* direct path index maint method (see aci8dp.h) */
#define ACI_ATTR_DIRPATH_INDEX_MAINT_METHOD 138

    /* parallel load: db file, initial and next extent sizes */

#define ACI_ATTR_DIRPATH_FILE               139      /* DB file to load into */
#define ACI_ATTR_DIRPATH_STSTGE_INITIAL    140       /* initial extent size */
#define ACI_ATTR_DIRPATH_STSTGE_NEXT       141          /* next extent size */
            /* direct path index maint method (see aci8dp.h) */
#define ACI_ATTR_DIRPATH_SKIPINDEX_METHOD   145

    /* 8.2 dpapi support of ADTs */
#define ACI_ATTR_DIRPATH_EXPR_TYPE  150        /* expr type of ACI_ATTR_NAME */

#define ACI_ATTR_DIRPATH_INPUT      151    /* input in text or stream format */
#define ACI_DIRPATH_INPUT_TEXT     0x01
#define ACI_DIRPATH_INPUT_STREAM   0x02
#define ACI_DIRPATH_INPUT_UNKNOWN  0x04

#define ACI_DIRPATH_COL_COMPLETE 0                /* column data is complete */
#define ACI_DIRPATH_COL_NULL     1                         /* column is null */
#define ACI_DIRPATH_COL_PARTIAL  2                 /* column data is partial */
#define ACI_DIRPATH_COL_ERROR    3               /* column error, ignore row */
/*----- values for action parameter to OCIDirPathDataSave -----*/
#define ACI_DIRPATH_DATASAVE_SAVEONLY 0              /* data save point only */
#define ACI_DIRPATH_DATASAVE_FINISH   1           /* execute finishing logic */

#define ACI_ATTR_DIRPATH_FN_CTX             167  /* fn ctx ADT attrs or args */

#define ACI_ATTR_DIRPATH_OID                187   /* loading into an OID col */
#define ACI_ATTR_DIRPATH_SID                194   /* loading into an SID col */
#define ACI_ATTR_DIRPATH_OBJ_CONSTR         206 /* obj type of subst obj tbl */

/* Attr to allow setting of the stream version PRIOR to calling Prepare */
#define ACI_ATTR_DIRPATH_STREAM_VERSION     212      /* version of the stream*/

#define ACIP_ATTR_DIRPATH_VARRAY_INDEX      213       /* varray index column */

/*------------- Supported Values for Direct Path Date cache -----------------*/
#define ACI_ATTR_DIRPATH_DCACHE_NUM         303        /* date cache entries */
#define ACI_ATTR_DIRPATH_DCACHE_SIZE        304          /* date cache limit */
#define ACI_ATTR_DIRPATH_DCACHE_MISSES      305         /* date cache misses */
#define ACI_ATTR_DIRPATH_DCACHE_HITS        306           /* date cache hits */
#define ACI_ATTR_DIRPATH_DCACHE_DISABLE     307 /* on set: disable datecache 
                                                * on overflow.
                                                * on get: datecache disabled? 
                                                * could be due to overflow
                                                * or others                  */

/*------------- Attributes for 10i Updates to the DirPath API ---------------*/
#define ACI_ATTR_DIRPATH_RESERVED_7         326                 /* reserved */
#define ACI_ATTR_DIRPATH_RESERVED_8         327                 /* reserved */
#define ACI_ATTR_DIRPATH_CONVERT            328 /* stream conversion needed? */
#define ACI_ATTR_DIRPATH_BADROW             329        /* info about bad row */
#define ACI_ATTR_DIRPATH_BADROW_LENGTH      330    /* length of bad row info */
#define ACI_ATTR_DIRPATH_WRITE_ORDER        331         /* column fill order */
#define ACI_ATTR_DIRPATH_GRANULE_SIZE       332   /* granule size for unload */
#define ACI_ATTR_DIRPATH_GRANULE_OFFSET     333    /* offset to last granule */
#define ACI_ATTR_DIRPATH_RESERVED_1         334                  /* reserved */
#define ACI_ATTR_DIRPATH_RESERVED_2         335                  /* reserved */

/*------ Attributes for 10i DirPathAPI conversion (NLS lang, terr, cs) ------*/
#define ACI_ATTR_DIRPATH_RESERVED_3         337                  /* reserved */
#define ACI_ATTR_DIRPATH_RESERVED_4         338                  /* reserved */
#define ACI_ATTR_DIRPATH_RESERVED_5         357                  /* reserved */
#define ACI_ATTR_DIRPATH_RESERVED_6         358                  /* reserved */

#define ACI_ATTR_DIRPATH_LOCK_WAIT          359    /* wait for lock in dpapi */
#define ACI_ATTR_LOB_TYPE                   591    /*Gets the LOB type from the LOB descriptor*/

/* 424 is used by ACI_ATTR_DRIVER_NAME */
/* --------- Attributes added to support server side session pool ---------- */
#define ACI_ATTR_DRIVER_NAME           424                    /* Driver Name */
#define ACI_ATTR_CONNECTION_CLASS  425
#define ACI_ATTR_PURITY            426

#define ACI_ATTR_PURITY_DEFAULT    0x00
#define ACI_ATTR_PURITY_NEW        0x01
#define ACI_ATTR_PURITY_SELF       0x02


#define ACI_ATTR_BATCH_BUFFER              1000
#define ACI_ATTR_EXECUTE_BATCH_SIZE        1001
#define ACI_ATTR_FETCH_SIZE                1002
#define ACI_ATTR_PREPARE_SIMPLE_EXECUTE    1003
#define ACI_ATTR_NET_DATA_BY_STR           1004
#define ACI_ATTR_SEND_FLOATINGNUMBER_KEEP_PRECISION 1005
#define ACI_ATTR_COMPRESS_MIN_SIZE         1006
#define ACI_ATTR_COMPATIBLE_OLD_PROTOCAL   1007
#define ACI_ATTR_SEND_OLD_STARTUP_PACKET   1008
#define ACI_ATTR_SOCKET_BLOCK_CONN			   1010
#define ACI_ATTR_SOCKET_CONNECT_TIMEOUT	   1011
#define ACI_ATTR_CHINESE_ERRORINFO        1020
#define ACI_ATTR_CASE_SENSITIVE           1021

/*------ keepalive相关属性 ------*/
#define ACI_ATTR_KEEPALIVES_ON				1100
#define ACI_ATTR_KEEPALIVES_IDLE			1101
#define ACI_ATTR_KEEPALIVES_INTERVAL		1102
#define ACI_ATTR_KEEPALIVES_COUNT			1103

#define ACI_ATTR_ENABLE_ENCODING			1104
#define ACI_ATTR_SERVER_ENCODING			1105

#define ACI_ATTR_RECONNECT_TIMEOUT			1106

//BULKIMP句柄相关属性
#define ACI_ATTR_MPP_IMP					1107
#define ACI_ATTR_MPP_LOAD_NODENUM			1108

/*------ Attributes for client to server charset conversion ratio -----------*/
#define ACI_ATTR_MAX_CHARSET_RATIO              517
#define ACI_ATTR_MAX_NCHARSET_RATIO             518

/*
* OCI SODA attributes
*/
/* OCI SODA collection and metadata atributes */
#define  ACI_ATTR_SODA_COLL_NAME                535
#define  ACI_ATTR_SODA_DESCRIPTOR               536
#define  ACI_ATTR_SODA_SCHEMA                   537
#define  ACI_ATTR_SODA_TABLE_NAME               538
#define  ACI_ATTR_SODA_VIEW_NAME                539
#define  ACI_ATTR_SODA_TABLESPACE               540
#define  ACI_ATTR_SODA_STORAGE_INIT_SIZE        541
#define  ACI_ATTR_SODA_STORAGE_INC_PCT          542
#define  ACI_ATTR_SODA_KEY_COL_NAME             543
#define  ACI_ATTR_SODA_KEY_SQL_TYPE             544
#define  ACI_ATTR_SODA_KEY_MAX_LEN              545
#define  ACI_ATTR_SODA_KEY_ASSIGN_METHOD        546
#define  ACI_ATTR_SODA_KEY_SEQ_NAME             547
#define  ACI_ATTR_SODA_CTNT_COL_NAME            548
#define  ACI_ATTR_SODA_CTNT_SQL_TYPE            549
#define  ACI_ATTR_SODA_CTNT_MAX_LEN             550
#define  ACI_ATTR_SODA_CTNT_VALIDATION          551
#define  ACI_ATTR_SODA_CTNT_COMPRESS            552
#define  ACI_ATTR_SODA_CTNT_CACHE               553
#define  ACI_ATTR_SODA_CTNT_ENCRYPT             554
#define  ACI_ATTR_SODA_CTNT_TABLESPACE          555
#define  ACI_ATTR_SODA_VERSION_COL_NAME         556
#define  ACI_ATTR_SODA_VERSION_METHOD           557
#define  ACI_ATTR_SODA_MODTIME_COL_NAME         558
#define  ACI_ATTR_SODA_MODTIME_INDEX            559
#define  ACI_ATTR_SODA_CRTIME_COL_NAME          560
#define  ACI_ATTR_SODA_MTYPE_COL_NAME           561
#define  ACI_ATTR_SODA_READONLY                 562
/* OCI SODA collection and metadata atributes */
#define  ACI_ATTR_SODA_KEY                       563   
#define  ACI_ATTR_SODA_LASTMOD_TIMESTAMP         564
#define  ACI_ATTR_SODA_CREATE_TIMESTAMP          565
#define  ACI_ATTR_SODA_VERSION                   566
#define  ACI_ATTR_SODA_CONTENT                   567
#define  ACI_ATTR_SODA_JSON_CHARSET_ID           568
#define  ACI_ATTR_SODA_DETECT_JSON_ENC           569
#define  ACI_ATTR_SODA_MEDIA_TYPE                571

/* OCI SODA Content Column's JSON storage format */
#define  ACI_ATTR_SODA_CTNT_FORMAT              572

/* 573 - 575 are free and be used in future if necessary */

/* OCI SODA Operation Options attributes */
#define  ACI_ATTR_SODA_FILTER                   576
#define  ACI_ATTR_SODA_SKIP                     577           
#define  ACI_ATTR_SODA_LIMIT                    578

/* Per Iteration array DML rowcount attribute */
#define ACI_ATTR_DML_ROW_COUNT_ARRAY       469
#define ACI_ATTR_RESERVED_470              470


/* OCI SODA Output Options attributes */
#define ACI_ATTR_SODA_DOC_COUNT                 593


/* OCI_DEFAULT can be passed as a valid SODA mode.
* It has no effect, i.e. it is a no-op
*/
#define ACI_SODA_ATOMIC_COMMIT                  0x00000001

/* OCISodaCollCreate specific modes */
#define ACI_SODA_COLL_CREATE_MAP                0x00010000
/* Create collection in MAP mode */

/* OCISodaIndexDrop specific modes */
#define ACI_SODA_INDEX_DROP_FORCE               0x00010000
/* Drop domain index with FORCE */

/* OCI SODA Document flags */
#define ACI_SODA_DETECT_JSON_ENC       0x00000001 /* Detect the JSON encoding */
#define ACI_SODA_AS_STORED             0x00000002
/* Retrieve as stored in BLOB column */
#define ACI_SODA_AS_AL32UTF8           0x00000004        /* Retrieve as UTF-8 */

/* The following are possilble values to be set for key validation */
#define  ACI_SODA_KEY_METHOD_UUID       1
#define  ACI_SODA_KEY_METHOD_GUID       2
#define  ACI_SODA_KEY_METHOD_SEQUENCE   3
#define  ACI_SODA_KEY_METHOD_CLIENT     4

/* The following are the possible values for content validation methods */
#define  ACI_SODA_JSON_VALIDATION_STRICT  1
#define  ACI_SODA_JSON_VALIDATION_LAX     2 
#define  ACI_SODA_JSON_VALIDATION_STD     3

/* Possible values for LOB compression mechanism */
#define  ACI_SODA_LOB_COMPRESS_NONE    1
#define  ACI_SODA_LOB_COMPRESS_HIGH    2
#define  ACI_SODA_LOB_COMPRESS_MEDIUM  3
#define  ACI_SODA_LOB_COMPRESS_LOW     4

/* Possible values for LOB encryption mechanism */
#define  ACI_SODA_LOB_ENCRYPT_NONE      1
#define  ACI_SODA_LOB_ENCRYPT_3DES168   2
#define  ACI_SODA_LOB_ENCRYPT_AES128    3
#define  ACI_SODA_LOB_ENCRYPT_AES192    4
#define  ACI_SODA_LOB_ENCRYPT_AES256    5

/* Possible methods for version generation */
#define  ACI_SODA_VERSION_UUID           1
#define  ACI_SODA_VERSION_TIMESTAMP      2
#define  ACI_SODA_VERSION_MD5            3
#define  ACI_SODA_VERSION_SHA256         4
#define  ACI_SODA_VERSION_SEQUENTIAL     5
#define  ACI_SODA_VERSION_NONE           6

/*------- 分发器相关属性 --------*/
#define ACI_ATTR_ENABLE_DISPATCH            1200
#define ACI_ATTR_HOST_PERCENTAGE_OF_STATEMENT	1201
#define ACI_ATTR_USE_ASYNCHRONOUS_SLAVE		1202
#define ACI_ATTR_SEND_LSN_TO_SLAVE			1203
//*************************数据库TEXT类型返回的数据长度*****************************
#define ACI_ATTR_DB_TEXT_MAX_LEN			1204

#define ACI_ATTR_DIRPATH_RESERVED_9        2000                  /* reserved */

/*------ Attribute for 10iR2 for column encryption for Direct Path API ------*/
#define ACI_ATTR_DIRPATH_RESERVED_10       2001       /* vector of functions */
#define ACI_ATTR_DIRPATH_RESERVED_11       2002       /* encryption metadata */

/*------ Attribute to determine last column successfully converted ----------*/
#define ACI_ATTR_CURRENT_ERRCOL            2003      /* current error column */

/* Add DirPathAPI attributes above.  Next value to be assigned is 2004       */

/* ------------------End of DirPathAPI attribute Section --------------------*/
/*---------------------------------------------------------------------------*/


/*---------------- Describe Handle Parameter Attribute Values ---------------*/

/* ACI_ATTR_CURSOR_COMMIT_BEHAVIOR */
#define ACI_CURSOR_OPEN   0 
#define ACI_CURSOR_CLOSED 1

/* ACI_ATTR_CATALOG_LOCATION */
#define ACI_CL_START 0
#define ACI_CL_END   1

/* ACI_ATTR_SAVEPOINT_SUPPORT */
#define ACI_SP_SUPPORTED   0
#define ACI_SP_UNSUPPORTED 1

/* ACI_ATTR_NOWAIT_SUPPORT */
#define ACI_NW_SUPPORTED   0
#define ACI_NW_UNSUPPORTED 1

/* ACI_ATTR_AUTOCOMMIT_DDL */
#define ACI_AC_DDL    0
#define ACI_NO_AC_DDL 1

/* ACI_ATTR_LOCKING_MODE */
#define ACI_LOCK_IMMEDIATE 0
#define ACI_LOCK_DELAYED   1

/* ------------------- Instance type attribute values -----------------------*/
#define ACI_INSTANCE_TYPE_UNKNOWN  0
#define ACI_INSTANCE_TYPE_RDBMS    1
#define ACI_INSTANCE_TYPE_OSM      2

/*---------------------------------------------------------------------------*/

/*---------------------------ACIPasswordChange-------------------------------*/
#define ACI_AUTH         0x08        /* Change the password but do not login */
#define ACI_CPW_SYSDBA   0x00000010      /* Password change with SYSDBA auth */
#define ACI_CPW_SYSOPER  0x00000020      /* Password change with SYSOPER auth */
#define ACI_CPW_SYSASM   0x00800040      /* Password change with SYSASM auth */
#define ACI_CPW_SYSBKP   0x00000080      /* Password change with SYSBACKUP auth */
#define ACI_CPW_SYSDGD   0x00000100      /* Password change with SYSDG auth */
#define ACI_CPW_SYSKMT   0x00000200      /* Password change with SYSKM auth */


/*------------------------Other Constants------------------------------------*/
#define ACI_MAX_FNS   100                     /* max number of ACI Functions */
#define ACI_SQLSTATE_SIZE 5  
#define ACI_ERROR_MAXMSG_SIZE   1024         /* max size of an error message */
#define ACI_ERROR_MAXMSG_SIZE2  3072          /* new len max size of an error message */
#define ACI_LOBMAXSIZE MINUB4MAXVAL                 /* maximum lob data size */
#define ACI_ROWID_LEN             23 
/*---------------------------------------------------------------------------*/

/*------------------------ Fail Over Events ---------------------------------*/
#define ACI_FO_END          0x00000001
#define ACI_FO_ABORT        0x00000002   
#define ACI_FO_REAUTH       0x00000004
#define ACI_FO_BEGIN        0x00000008 
#define ACI_FO_ERROR        0x00000010
/*---------------------------------------------------------------------------*/

/*------------------------ Fail Over Callback Return Codes ------------------*/
#define ACI_FO_RETRY        25410
/*---------------------------------------------------------------------------*/

/*------------------------- Fail Over Types ---------------------------------*/
#define ACI_FO_NONE           0x00000001
#define ACI_FO_SESSION        0x00000002
#define ACI_FO_SELECT         0x00000004
#define ACI_FO_TXNAL          0x00000008
/*---------------------------------------------------------------------------*/

/*--------------------- ACI_ATTR_VARTYPE_MAXLEN_COMPAT values ---------------*/
#define ACI_ATTR_MAXLEN_COMPAT_STANDARD 1
#define ACI_ATTR_MAXLEN_COMPAT_EXTENDED 2
/*---------------------------------------------------------------------------*/

/*-----------------------Function Codes--------------------------------------*/
#define ACI_FNCODE_INITIALIZE     1                         /* ACIInitialize */
#define ACI_FNCODE_HANDLEALLOC  2                          /* ACIHandleAlloc */
#define ACI_FNCODE_HANDLEFREE  3                            /* ACIHandleFree */
#define ACI_FNCODE_DESCRIPTSTLLOC  4                   /* ACIDescriptorAlloc */
#define ACI_FNCODE_DESCRIPTORFREE  5                    /* ACIDescriptorFree */
#define ACI_FNCODE_ENVINIT   6                                 /* ACIEnvInit */
#define ACI_FNCODE_SERVERATTACH   7                       /* ACIServerAttach */
#define ACI_FNCODE_SERVERDETACH   8                       /* ACIServerDetach */
/* unused         9 */ 
#define ACI_FNCODE_SESSIONBEGIN  10                       /* ACISessionBegin */
#define ACI_FNCODE_SESSIONEND   11                          /* ACISessionEnd */
#define ACI_FNCODE_PASSWORDCHANGE   12                  /* ACIPasswordChange */
#define ACI_FNCODE_STMTPREPARE   13                        /* ACIStmtPrepare */
                                                      /* unused       14- 16 */
#define ACI_FNCODE_BINDDYNAMIC   17                        /* ACIBindDynamic */
#define ACI_FNCODE_BINDOBJECT  18                           /* ACIBindObject */
                                                                /* 19 unused */
#define ACI_FNCODE_BINDARRAYOFSTRUCT   20            /* ACIBindArrayOfStruct */
#define ACI_FNCODE_STMTEXECUTE  21                         /* ACIStmtExecute */
                                                             /* unused 22-24 */
#define ACI_FNCODE_DEFINEOBJECT  25                       /* ACIDefineObject */
#define ACI_FNCODE_DEFINEDYNAMIC   26                    /* ACIDefineDynamic */
#define ACI_FNCODE_DEFINEARRAYOFSTRUCT  27         /* ACIDefineArrayOfStruct */
#define ACI_FNCODE_STMTFETCH   28                            /* ACIStmtFetch */
#define ACI_FNCODE_STMTGETBIND   29                    /* ACIStmtGetBindInfo */
                                                            /* 30, 31 unused */
#define ACI_FNCODE_DESCRIBEANY  32                         /* ACIDescribeAny */
#define ACI_FNCODE_TRANSSTART  33                           /* ACITransStart */
#define ACI_FNCODE_TRANSDETACH  34                         /* ACITransDetach */
#define ACI_FNCODE_TRANSCOMMIT  35                         /* ACITransCommit */
                                                                /* 36 unused */
#define ACI_FNCODE_ERRORGET   37                              /* ACIErrorGet */
#define ACI_FNCODE_LOBOPENFILE  38                         /* ACILobFileOpen */
#define ACI_FNCODE_LOBCLOSEFILE  39                       /* ACILobFileClose */
                                             /* 40 was LOBCREATEFILE, unused */
                                         /* 41 was ACILobFileDelete, unused  */
#define ACI_FNCODE_LOBCOPY  42                                 /* ACILobCopy */
#define ACI_FNCODE_LOBAPPEND  43                             /* ACILobAppend */
#define ACI_FNCODE_LOBERASE  44                               /* ACILobErase */
#define ACI_FNCODE_LOBLENGTH  45                          /* ACILobGetLength */
#define ACI_FNCODE_LOBTRIM  46                                 /* ACILobTrim */
#define ACI_FNCODE_LOBREAD  47                                 /* ACILobRead */
#define ACI_FNCODE_LOBWRITE  48                               /* ACILobWrite */
                                                                /* 49 unused */
#define ACI_FNCODE_SVCCTXBREAK 50                                /* ACIBreak */
#define ACI_FNCODE_SERVERVERSION  51                     /* ACIServerVersion */

#define ACI_FNCODE_KERBATTRSET 52                          /* ACIKerbAttrSet */

/* unused 53 */

#define ACI_FNCODE_ATTRGET 54                                  /* ACIAttrGet */
#define ACI_FNCODE_ATTRSET 55                                  /* ACIAttrSet */
#define ACI_FNCODE_PARAMSET 56                                /* ACIParamSet */
#define ACI_FNCODE_PARAMGET 57                                /* ACIParamGet */
#define ACI_FNCODE_STMTGETPIECEINFO   58              /* ACIStmtGetPieceInfo */
#define ACI_FNCODE_LDATOSVCCTX 59                          /* ACILdaToSvcCtx */
                                                                /* 60 unused */
#define ACI_FNCODE_STMTSETPIECEINFO   61              /* ACIStmtSetPieceInfo */
#define ACI_FNCODE_TRANSFORGET 62                          /* ACITransForget */
#define ACI_FNCODE_TRANSPREPARE 63                        /* ACITransPrepare */
#define ACI_FNCODE_TRANSROLLBACK  64                     /* ACITransRollback */
#define ACI_FNCODE_DEFINEBYPOS 65                          /* ACIDefineByPos */
#define ACI_FNCODE_BINDBYPOS 66                              /* ACIBindByPos */
#define ACI_FNCODE_BINDBYNAME 67                            /* ACIBindByName */
#define ACI_FNCODE_LOBASSIGN  68                             /* ACILobAssign */
#define ACI_FNCODE_LOBISEQUAL  69                           /* ACILobIsEqual */
#define ACI_FNCODE_LOBISINIT  70                      /* ACILobLocatorIsInit */

#define ACI_FNCODE_LOBENABLEBUFFERING  71           /* ACILobEnableBuffering */
#define ACI_FNCODE_LOBCHARSETID  72                       /* ACILobCharSetID */
#define ACI_FNCODE_LOBCHARSETFORM  73                   /* ACILobCharSetForm */
#define ACI_FNCODE_LOBFILESETNAME  74                   /* ACILobFileSetName */
#define ACI_FNCODE_LOBFILEGETNAME  75                   /* ACILobFileGetName */
#define ACI_FNCODE_LOGON 76                                      /* ACILogon */
#define ACI_FNCODE_LOGOFF 77                                    /* ACILogoff */
#define ACI_FNCODE_LOBDISABLEBUFFERING 78          /* ACILobDisableBuffering */
#define ACI_FNCODE_LOBFLUSHBUFFER 79                    /* ACILobFlushBuffer */
#define ACI_FNCODE_LOBLOADFROMFILE 80                  /* ACILobLoadFromFile */

#define ACI_FNCODE_LOBOPEN  81                                 /* ACILobOpen */
#define ACI_FNCODE_LOBCLOSE  82                               /* ACILobClose */
#define ACI_FNCODE_LOBISOPEN  83                             /* ACILobIsOpen */
#define ACI_FNCODE_LOBFILEISOPEN  84                     /* ACILobFileIsOpen */
#define ACI_FNCODE_LOBFILEEXISTS  85                     /* ACILobFileExists */
#define ACI_FNCODE_LOBFILECLOSEALL  86                 /* ACILobFileCloseAll */
#define ACI_FNCODE_LOBCREATETEMP  87                /* ACILobCreateTemporary */
#define ACI_FNCODE_LOBFREETEMP  88                    /* ACILobFreeTemporary */
#define ACI_FNCODE_LOBISTEMP  89                        /* ACILobIsTemporary */

#define ACI_FNCODE_AQENQ  90                                     /* ACIAQEnq */
#define ACI_FNCODE_AQDEQ  91                                     /* ACIAQDeq */
#define ACI_FNCODE_RESET  92                                     /* ACIReset */
#define ACI_FNCODE_SVCCTXTOLDA  93                         /* ACISvcCtxToLda */
#define ACI_FNCODE_LOBLOCATSTSSIGN 94                /* ACILobLocatorAssign */

#define ACI_FNCODE_UBINDBYNAME 95

#define ACI_FNCODE_AQLISTEN  96                               /* ACIAQListen */

#define ACI_FNCODE_SVC2HST 97                                    /* reserved */
#define ACI_FNCODE_SVCRH   98                                    /* reserved */
                           /* 97 and 98 are reserved for ShenTong internal use */

#define ACI_FNCODE_TRANSMULTIPREPARE   99            /* ACITransMultiPrepare */

#define ACI_FNCODE_CPOOLCREATE  100               /* ACIConnectionPoolCreate */
#define ACI_FNCODE_CPOOLDESTROY 101              /* ACIConnectionPoolDestroy */
#define ACI_FNCODE_LOGON2 102                                   /* ACILogon2 */
#define ACI_FNCODE_ROWIDTOCHAR  103                        /* ACIRowidToChar */

#define ACI_FNCODE_SPOOLCREATE  104                  /* ACISessionPoolCreate */
#define ACI_FNCODE_SPOOLDESTROY 105                 /* ACISessionPoolDestroy */
#define ACI_FNCODE_SESSIONGET   106                         /* ACISessionGet */
#define ACI_FNCODE_SESSIONRELEASE 107                   /* ACISessionRelease */
#define ACI_FNCODE_STMTPREPARE2 108                       /* ACIStmtPrepare2 */
#define ACI_FNCODE_STMTRELEASE 109                         /* ACIStmtRelease */
#define ACI_FNCODE_AQENQARRAY  110                          /* ACIAQEnqArray */
#define ACI_FNCODE_AQDEQARRAY  111                          /* ACIAQDeqArray */
#define ACI_FNCODE_LOBCOPY2    112                            /* ACILobCopy2 */
#define ACI_FNCODE_LOBERASE2   113                           /* ACILobErase2 */
#define ACI_FNCODE_LOBLENGTH2  114                       /* ACILobGetLength2 */
#define ACI_FNCODE_LOBLOADFROMFILE2  115              /* ACILobLoadFromFile2 */
#define ACI_FNCODE_LOBREAD2    116                            /* ACILobRead2 */
#define ACI_FNCODE_LOBTRIM2    117                            /* ACILobTrim2 */
#define ACI_FNCODE_LOBWRITE2   118                           /* ACILobWrite2 */
#define ACI_FNCODE_LOBGETSTSTGELIMIT 119           /* ACILobGetStorageLimit */
#define ACI_FNCODE_DBSTARTUP 120                             /* ACIDBStartup */
#define ACI_FNCODE_DBSHUTDOWN 121                           /* ACIDBShutdown */
#define ACI_FNCODE_LOBARRAYREAD       122                 /* ACILobArrayRead */
#define ACI_FNCODE_LOBARRAYWRITE      123                /* ACILobArrayWrite */
#define ACI_FNCODE_DateTimeConstruct  124            /* ACIDateTimeConstruct */
#define ACI_FNCODE_DateTimeGetDate  125                /* ACIDateTimeGetDate */
#define ACI_FNCODE_DateTimeGetTime  126                /* ACIDateTimeGetTime */
#define ACI_FNCODE_IntervalGetDaySecond 127    /*　ACIIntervalGetDaySecond　*/
#define ACI_FNCODE_INtervalFromText 128               /* ACIIntervalFromText */
#define ACI_FNCODE_LastInsertId 130                       /* ACILastInsertId */
#define ACI_FNCODE_SERVERRELEASE  131                    /* ACIServerRelease */
#define ACI_FNCODE_SERVERRELEASE2  132                  /* ACIServerRelease2 */
#define ACI_FNCODE_MAXFCN 128                   /* maximum ACI function code */
#define ACI_FNCODE_ARRAYDESCRIPTSTLLOC  140       /* ACIArrayDescriptorAlloc */
#define ACI_FNCODE_ARRAYDESCRIPTORFREE  141        /* ACIArrayDescriptorFree */
#define ACI_FNCODE_SVCCTXRESET 142                                /* ACIReset */

/*---------------------------------------------------------------------------*/

/*---------------Statement Cache callback modes-----------------------------*/
#define ACI_CBK_STMTCACHE_STMTPURGE  0x01

/*-----------------------Handle Definitions----------------------------------*/
typedef struct ACIEnv           ACIEnv;            /* ACI environment handle */
typedef struct ACIError         ACIError;                /* ACI error handle */
typedef struct ACISvcCtx        ACISvcCtx;             /* ACI service handle */
typedef struct ACIStmt          ACIStmt;             /* ACI statement handle */
typedef struct ACIBind          ACIBind;                  /* ACI bind handle */
typedef struct ACIDefine        ACIDefine;              /* ACI Define handle */
typedef struct ACIDescribe      ACIDescribe;          /* ACI Describe handle */
typedef struct ACIServer        ACIServer;              /* ACI Server handle */
typedef struct ACISession       ACISession;     /* ACI Authentication handle */
typedef struct ACIComplexObject ACIComplexObject;          /* ACI COR handle */
typedef struct ACITrans         ACITrans;          /* ACI Transaction handle */
typedef struct ACISecurity      ACISecurity;          /* ACI Security handle */
typedef struct ACISubscription  ACISubscription;      /* subscription handle */
typedef struct ACIBulk          ACIBulk;           /* ACI bulk insert handle */
typedef struct ACIHIMP			ACIHIMP;           /* ACI bulk import handle */
typedef struct ACIDirPathCtx		ACIDirPathCtx;
typedef struct ACIDirPathColArray	ACIDirPathColArray;
typedef struct ACIDirPathStream		ACIDirPathStream;
typedef struct ACIRaw			ACIRaw;
typedef struct ACIString		ACIString;   /* ACIString */

typedef struct ACICPool         ACICPool;          /* connection pool handle */
typedef struct ACICPool         ACISPool;             /* session pool handle */
typedef struct ACISession      ACIAuthInfo;                  /* auth handle */
typedef struct ACIAdmin         ACIAdmin;                    /* admin handle */
typedef struct ACIEvent         ACIEvent;                 /* HA event handle */

/*-----------------------Descriptor Definitions------------------------------*/
typedef struct ACISnapshot      ACISnapshot;      /* ACI snapshot descriptor */
typedef struct ACIResult        ACIResult;      /* ACI Result Set Descriptor */
typedef struct ACILobLocator    ACILobLocator; /* ACI Lob Locator descriptor */
typedef struct ACIParam         ACIParam;        /* ACI PARameter descriptor */
typedef struct ACIComplexObjectComp ACIComplexObjectComp;
                                                       /* ACI COR descriptor */

typedef struct ACIDateTime ACIDateTime;           /* ACI DateTime descriptor */
typedef struct ACIInterval ACIInterval;           /* ACI Interval descriptor */

typedef struct ACIUcb           ACIUcb;      /* ACI User Callback descriptor */
typedef struct ACIServerDNs     ACIServerDNs;    /* ACI server DN descriptor */
typedef struct ACIJson			ACIJson;		 /* ACI Json descriptor */
typedef struct ACIRowid         ACIRowid;        /* ACI ROWID descriptor */

/*-------------------------- AQ Descriptors ---------------------------------*/
typedef struct ACIAQEnqOptions    ACIAQEnqOptions; /* AQ Enqueue Options hdl */
typedef struct ACIAQDeqOptions    ACIAQDeqOptions; /* AQ Dequeue Options hdl */
typedef struct ACIAQMsgProperties ACIAQMsgProperties;  /* AQ Mesg Properties */
typedef struct ACIAQAgent         ACIAQAgent;         /* AQ Agent descriptor */
typedef struct ACIAQNfyDescriptor ACIAQNfyDescriptor;   /* AQ Nfy descriptor */
typedef struct ACIAQSignature     ACIAQSignature;            /* AQ Siganture */
typedef struct ACIAQListenOpts    ACIAQListenOpts;      /* AQ listen options */
typedef struct ACIAQLisMsgProps   ACIAQLisMsgProps;   /* AQ listen msg props */

/*---------------------------------------------------------------------------*/


/*--------------------- OCI Thread Object Definitions------------------------*/

/* ACIThread Context */
typedef struct ACIThreadContext ACIThreadContext;

/* ACIThread Mutual Exclusion Lock */
typedef struct ACIThreadMutex   ACIThreadMutex;

/* ACIThread Key for Thread-Specific Data */
typedef struct ACIThreadKey     ACIThreadKey;

/* ACIThread Thread ID */
typedef struct ACIThreadId      ACIThreadId;

/* ACIThread Thread Handle */
typedef struct ACIThreadHandle  ACIThreadHandle;

/*-------------------- ACI Thread Callback Function Pointers ----------------*/

/* ACIThread Key Destructor Function Type */
typedef void(*ACIThreadKeyDestFunc)(void  *);


/*---------------------------------------------------------------------------*/
/* OCI SODA typedefs */
typedef struct ACISodaColl				ACISodaColl;        /* OCI SODA collection handle */
typedef struct ACISodaDoc				ACISodaDoc;            /* OCI SODA document handle */
typedef struct ACISodaDocCursor			ACISodaDocCursor;/* OCI SODA document cursor */
typedef struct ACISodaOperationOptions	ACISodaOperationOptions;
/*OCI SODA document cursor */
typedef struct ACISodaOutputOptions		ACISodaOutputOptions;
/* OCI SODA output optns */
typedef struct ACISodaMetadata			ACISodaMetadata;
/* OCI SODA metadata of a collection*/
typedef struct ACISodaCollCursor		ACISodaCollCursor;
/* OCI SODA collection cursor */

/*---------------------------------------------------------------------------*/
 
/* Lob typedefs for Pro*C */
typedef struct ACILobLocator ACIClobLocator;    /* ACI Character LOB Locator */
typedef struct ACILobLocator ACIBlobLocator;       /* ACI Binary LOB Locator */
typedef struct ACILobLocator ACIBFileLocator; /* ACI Binary LOB File Locator */
/*---------------------------------------------------------------------------*/

/* Undefined value for tz in interval types*/
#define ACI_INTHR_UNK 24

/* -------------------------- Implicit Result types ------------------------ */
#define ACI_RESULT_TYPE_SELECT                1

  /* These defined adjustment values */
#define ACI_ADJUST_UNK            10
#define ACI_SHENTONG_DATE           0
#define ACI_ANSI_DATE             1

/*------------------------ Lob-specific Definitions -------------------------*/

/*
 * aciloff - ACI Lob OFFset
 *
 * The offset in the lob data.  The offset is specified in terms of bytes for
 * BLOBs and BFILes.  Character offsets are used for CLOBs, NCLOBs.
 * The maximum size of internal lob data is 4 gigabytes.  FILE LOB 
 * size is limited by the operating system.
 */
typedef ub4 ACILobOffset;

/*
 * acillen - ACI Lob LENgth (of lob data)
 *
 * Specifies the length of lob data in bytes for BLOBs and BFILes and in 
 * characters for CLOBs, NCLOBs.  The maximum length of internal lob
 * data is 4 gigabytes.  The length of FILE LOBs is limited only by the
 * operating system.
 */
typedef ub4 ACILobLength;
/*
 * acilmo - ACI Lob open MOdes
 *
 * The mode specifies the planned operations that will be performed on the
 * FILE lob data.  The FILE lob can be opened in read-only mode only.
 * 
 * In the future, we may include read/write, append and truncate modes.  Append
 * is equivalent to read/write mode except that the FILE is positioned for
 * writing to the end.  Truncate is equivalent to read/write mode except that
 * the FILE LOB data is first truncated to a length of 0 before use.
 */
enum ACILobMode
{
  ACI_LOBMODE_READONLY = 1,                                     /* read-only */
  ACI_LOBMODE_READWRITE = 2             /* read_write for internal lobs only */
};
typedef enum ACILobMode ACILobMode;

/*---------------------------------------------------------------------------*/


/*----------------------------Piece Definitions------------------------------*/

/* if acidef.h is being included in the app, acidef.h should precede aci.h */

/* 
 * since clients may  use aci.h, acidef.h and acidfn.h the following defines
 * need to be guarded, usually internal clients
 */

#ifndef ACI_FLAGS
#define ACI_FLAGS
#define ACI_ONE_PIECE 0                                         /* one piece */
#define ACI_FIRST_PIECE 1                                 /* the first piece */
#define ACI_NEXT_PIECE 2                          /* the next of many pieces */
#define ACI_LAST_PIECE 3                                   /* the last piece */
#endif
/*---------------------------------------------------------------------------*/

/*--------------------------- FILE open modes -------------------------------*/
#define ACI_FILE_READONLY 1             /* readonly mode open for FILE types */
#define ACI_FILE_READ_ONLY      ACI_FILE_READONLY 
#define ACI_FILE_READWRITE 2
#define ACI_FILE_READ_WRITE		ACI_FILE_READWRITE
/*---------------------------------------------------------------------------*/
/*--------------------------- LOB open modes --------------------------------*/
#define ACI_LOB_READONLY 1              /* readonly mode open for ILOB types */
#define ACI_LOB_READWRITE 2                /* read write mode open for ILOBs */
#define ACI_LOB_WRITEONLY 3				/* writeonly mode open for ILOB types */

/*----------------------- LOB Buffering Flush Flags -------------------------*/
#define ACI_LOB_BUFFER_FREE   1 
#define ACI_LOB_BUFFER_NOFREE 2
/*---------------------------------------------------------------------------*/

/*--------------------------- ACI Statement Types ---------------------------*/
#define  ACI_STMT_UNKNOWN 0                              /* unknown statement*/
#define  ACI_STMT_SELECT  1                              /* select statement */
#define  ACI_STMT_UPDATE  2                              /* update statement */
#define  ACI_STMT_DELETE  3                              /* delete statement */
#define  ACI_STMT_INSERT  4                              /* Insert Statement */
#define  ACI_STMT_CREATE  5                              /* create statement */
#define  ACI_STMT_DROP    6                                /* drop statement */
#define  ACI_STMT_ALTER   7                               /* alter statement */
#define  ACI_STMT_BEGIN   8                   /* begin ... (pl/sql statement)*/
#define  ACI_STMT_DECLARE 9                /* declare .. (pl/sql statement ) */
#define  ACI_STMT_CALL	  10					  /* corresponds to kpu call */
#define  ACI_STMT_MERGE   16							  /* merge statement */
/*---------------------------------------------------------------------------*/

/*--------------------------- ACI Parameter Types ---------------------------*/
#define ACI_PTYPE_UNK                 0                         /* unknown   */
#define ACI_PTYPE_TABLE               1                         /* table     */
#define ACI_PTYPE_VIEW                2                         /* view      */
#define ACI_PTYPE_PROC                3                         /* procedure */
#define ACI_PTYPE_FUNC                4                         /* function  */
#define ACI_PTYPE_PKG                 5                         /* package   */
#define ACI_PTYPE_TYPE                6                 /* user-defined type */
#define ACI_PTYPE_SYN                 7                         /* synonym   */
#define ACI_PTYPE_SEQ                 8                         /* sequence  */
#define ACI_PTYPE_COL                 9                         /* column    */
#define ACI_PTYPE_ARG                 10                        /* argument  */
#define ACI_PTYPE_LIST                11                        /* list      */
#define ACI_PTYPE_TYPE_ATTR           12    /* user-defined type's attribute */
#define ACI_PTYPE_TYPE_COLL           13        /* collection type's element */
#define ACI_PTYPE_TYPE_METHOD         14       /* user-defined type's method */
#define ACI_PTYPE_TYPE_ARG            15   /* user-defined type method's arg */
#define ACI_PTYPE_TYPE_RESULT         16/* user-defined type method's result */
#define ACI_PTYPE_SCHEMA              17                           /* schema */
#define ACI_PTYPE_DATABASE            18                         /* database */
#define ACI_PTYPE_RULE                19                             /* rule */
#define ACI_PTYPE_RULE_SET            20                         /* rule set */
#define ACI_PTYPE_EVALUATION_CONTEXT  21               /* evaluation context */
#define ACI_PTYPE_TABLE_ALIAS         22                      /* table alias */
#define ACI_PTYPE_VARIABLE_TYPE       23                    /* variable type */
#define ACI_PTYPE_NAME_VALUE          24                  /* name value pair */
#define ACI_PTYPE_MPP_TABLE           25                        /* MPP table */

/*---------------------------------------------------------------------------*/

/*----------------------------- ACI List Types ------------------------------*/
#define ACI_LTYPE_UNK           0                               /* unknown   */
#define ACI_LTYPE_COLUMN        1                             /* column list */
#define ACI_LTYPE_ARG_PROC      2                 /* procedure argument list */
#define ACI_LTYPE_ARG_FUNC      3                  /* function argument list */
#define ACI_LTYPE_SUBPRG        4                         /* subprogram list */
#define ACI_LTYPE_TYPE_ATTR     5                          /* type attribute */
#define ACI_LTYPE_TYPE_METHOD   6                             /* type method */
#define ACI_LTYPE_TYPE_ARG_PROC 7    /* type method w/o result argument list */
#define ACI_LTYPE_TYPE_ARG_FUNC 8      /* type method w/result argument list */
#define ACI_LTYPE_SCH_OBJ       9                      /* schema object list */
#define ACI_LTYPE_DB_SCH        10                   /* database schema list */
#define ACI_LTYPE_TYPE_SUBTYPE  11                           /* subtype list */
#define ACI_LTYPE_TABLE_ALIAS   12                       /* table alias list */
#define ACI_LTYPE_VARIABLE_TYPE 13                     /* variable type list */
#define ACI_LTYPE_NAME_VALUE    14                        /* name value list */

/*---------------------------------------------------------------------------*/

/*-------------------------- Memory Cartridge Services ---------------------*/
#define ACI_MEMORY_CLEARED  1

/*-------------------------- Pickler Cartridge Services ---------------------*/
typedef struct ACIPicklerTdsCtx ACIPicklerTdsCtx;
typedef struct ACIPicklerTds ACIPicklerTds;
typedef struct ACIPicklerImage ACIPicklerImage;
typedef struct ACIPicklerFdo ACIPicklerFdo;
typedef ub4 ACIPicklerTdsElement;

typedef struct ACIAnyData ACIAnyData;

typedef struct ACIAnyDataSet ACIAnyDataSet;
typedef struct ACIAnyDataCtx ACIAnyDataCtx;

/*---------------------------------------------------------------------------*/

/*--------------------------- User Callback Constants -----------------------*/
#define ACI_UCBTYPE_ENTRY       1                          /* entry callback */
#define ACI_UCBTYPE_EXIT        2                           /* exit callback */
#define ACI_UCBTYPE_REPLACE     3                    /* replacement callback */

/*---------------------------------------------------------------------------*/

/*--------------------- NLS service type and constance ----------------------*/
#define ACI_NLS_DAYNAME1      1                    /* Native name for Monday */
#define ACI_NLS_DAYNAME2      2                   /* Native name for Tuesday */
#define ACI_NLS_DAYNAME3      3                 /* Native name for Wednesday */
#define ACI_NLS_DAYNAME4      4                  /* Native name for Thursday */
#define ACI_NLS_DAYNAME5      5                    /* Native name for Friday */
#define ACI_NLS_DAYNAME6      6              /* Native name for for Saturday */
#define ACI_NLS_DAYNAME7      7                /* Native name for for Sunday */
#define ACI_NLS_ABDAYNAME1    8        /* Native abbreviated name for Monday */
#define ACI_NLS_ABDAYNAME2    9       /* Native abbreviated name for Tuesday */
#define ACI_NLS_ABDAYNAME3    10    /* Native abbreviated name for Wednesday */
#define ACI_NLS_ABDAYNAME4    11     /* Native abbreviated name for Thursday */
#define ACI_NLS_ABDAYNAME5    12       /* Native abbreviated name for Friday */
#define ACI_NLS_ABDAYNAME6    13 /* Native abbreviated name for for Saturday */
#define ACI_NLS_ABDAYNAME7    14   /* Native abbreviated name for for Sunday */
#define ACI_NLS_MONTHNAME1    15                  /* Native name for January */
#define ACI_NLS_MONTHNAME2    16                 /* Native name for February */
#define ACI_NLS_MONTHNAME3    17                    /* Native name for March */
#define ACI_NLS_MONTHNAME4    18                    /* Native name for April */
#define ACI_NLS_MONTHNAME5    19                      /* Native name for May */
#define ACI_NLS_MONTHNAME6    20                     /* Native name for June */
#define ACI_NLS_MONTHNAME7    21                     /* Native name for July */
#define ACI_NLS_MONTHNAME8    22                   /* Native name for August */
#define ACI_NLS_MONTHNAME9    23                /* Native name for September */
#define ACI_NLS_MONTHNAME10   24                  /* Native name for October */
#define ACI_NLS_MONTHNAME11   25                 /* Native name for November */
#define ACI_NLS_MONTHNAME12   26                 /* Native name for December */
#define ACI_NLS_ABMONTHNAME1  27      /* Native abbreviated name for January */
#define ACI_NLS_ABMONTHNAME2  28     /* Native abbreviated name for February */
#define ACI_NLS_ABMONTHNAME3  29        /* Native abbreviated name for March */
#define ACI_NLS_ABMONTHNAME4  30        /* Native abbreviated name for April */
#define ACI_NLS_ABMONTHNAME5  31          /* Native abbreviated name for May */
#define ACI_NLS_ABMONTHNAME6  32         /* Native abbreviated name for June */
#define ACI_NLS_ABMONTHNAME7  33         /* Native abbreviated name for July */
#define ACI_NLS_ABMONTHNAME8  34       /* Native abbreviated name for August */
#define ACI_NLS_ABMONTHNAME9  35    /* Native abbreviated name for September */
#define ACI_NLS_ABMONTHNAME10 36      /* Native abbreviated name for October */
#define ACI_NLS_ABMONTHNAME11 37     /* Native abbreviated name for November */
#define ACI_NLS_ABMONTHNAME12 38     /* Native abbreviated name for December */
#define ACI_NLS_YES           39   /* Native string for affirmative response */
#define ACI_NLS_NO            40                 /* Native negative response */
#define ACI_NLS_AM            41           /* Native equivalent string of AM */
#define ACI_NLS_PM            42           /* Native equivalent string of PM */
#define ACI_NLS_AD            43           /* Native equivalent string of AD */
#define ACI_NLS_BC            44           /* Native equivalent string of BC */
#define ACI_NLS_DECIMAL       45                        /* decimal character */
#define ACI_NLS_GROUP         46                          /* group separator */
#define ACI_NLS_DEBIT         47                   /* Native symbol of debit */
#define ACI_NLS_CREDIT        48                  /* Native sumbol of credit */
#define ACI_NLS_DATEFORMAT    49                       /* ShenTong date format */
#define ACI_NLS_INT_CURRENCY  50            /* International currency symbol */
#define ACI_NLS_LOC_CURRENCY  51                   /* Locale currency symbol */
#define ACI_NLS_LANGUAGE      52                            /* Language name */
#define ACI_NLS_ABLANGUAGE    53           /* Abbreviation for language name */
#define ACI_NLS_TERRITORY     54                           /* Territory name */
#define ACI_NLS_CHARACTER_SET 55                       /* Character set name */
#define ACI_NLS_LINGUISTIC_NAME    56                     /* Linguistic name */
#define ACI_NLS_CALENDAR      57                            /* Calendar name */
#define ACI_NLS_DUAL_CURRENCY 78                     /* Dual currency symbol */
#define ACI_NLS_WRITINGDIR    79               /* Language writing direction */
#define ACI_NLS_ABTERRITORY   80                   /* Territory Abbreviation */
#define ACI_NLS_DDATEFORMAT   81               /* ShenTong default date format */
#define ACI_NLS_DTIMEFORMAT   82               /* ShenTong default time format */
#define ACI_NLS_SFDATEFORMAT  83       /* Local string formatted date format */
#define ACI_NLS_SFTIMEFORMAT  84       /* Local string formatted time format */
#define ACI_NLS_NUMGROUPING   85                   /* Number grouping fields */
#define ACI_NLS_LISTSEP       86                           /* List separator */
#define ACI_NLS_MONDECIMAL    87               /* Monetary decimal character */
#define ACI_NLS_MONGROUP      88                 /* Monetary group separator */
#define ACI_NLS_MONGROUPING   89                 /* Monetary grouping fields */
#define ACI_NLS_INT_CURRENCYSEP 90       /* International currency separator */
#define ACI_NLS_CHARSET_MAXBYTESZ 91     /* Maximum character byte size      */
#define ACI_NLS_CHARSET_FIXEDWIDTH 92    /* Fixed-width charset byte size    */
#define ACI_NLS_CHARSET_ID    93                         /* Character set id */
#define ACI_NLS_NCHARSET_ID   94                        /* NCharacter set id */

#define ACI_NLS_MAXBUFSZ   100 /* Max buffer size may need for ACINlsGetInfo */

#define ACI_NLS_BINARY            0x1           /* for the binary comparison */
#define ACI_NLS_LINGUISTIC        0x2           /* for linguistic comparison */
#define ACI_NLS_CASE_INSENSITIVE  0x10    /* for case-insensitive comparison */

#define ACI_NLS_UPPERCASE         0x20               /* convert to uppercase */
#define ACI_NLS_LOWERCASE         0x40               /* convert to lowercase */

#define ACI_NLS_CS_IANA_TO_ST   0   /* Map charset name from IANA to ShenTong */
#define ACI_NLS_CS_ST_TO_IANA   1   /* Map charset name from ShenTong to IANA */
#define ACI_NLS_LANG_ISO_TO_ST  2   /* Map language name from ISO to ShenTong */
#define ACI_NLS_LANG_ST_TO_ISO  3   /* Map language name from ShenTong to ISO */
#define ACI_NLS_TERR_ISO_TO_ST  4   /* Map territory name from ISO to ShenTong*/
#define ACI_NLS_TERR_ST_TO_ISO  5   /* Map territory name from ShenTong to ISO*/
#define ACI_NLS_TERR_ISO3_TO_ST 6   /* Map territory name from 3-letter ISO */
                                     /* abbreviation to ShenTong               */
#define ACI_NLS_TERR_ST_TO_ISO3 7   /* Map territory name from ShenTong to    */
                                     /* 3-letter ISO abbreviation            */

typedef struct ACIMsg  ACIMsg;
typedef ub4            ACIWchar;

#define ACI_XMLTYPE_CREATE_ACISTRING 1
#define ACI_XMLTYPE_CREATE_CLOB      2
#define ACI_XMLTYPE_CREATE_BLOB      3

/*------------------------- Kerber Authentication Modes ---------------------*/
#define ACI_KERBCRED_PROXY               1 /* Apply Kerberos Creds for Proxy */
#define ACI_KERBCRED_CLIENT_IDENTIFIER   2/*Apply Creds for Secure Client ID */

/*------------------------- Database Startup Flags --------------------------*/
#define ACI_DBSTARTUPFLAG_FORCE 0x00000001  /* Abort running instance, start */
#define ACI_DBSTARTUPFLAG_RESTRICT 0x00000002      /* Restrict access to DBA */

/*------------------------- Database Shutdown Modes -------------------------*/
#define ACI_DBSHUTDOWN_TRANSACTIONAL      1 /* Wait for all the transactions */
#define ACI_DBSHUTDOWN_TRANSACTIONAL_LOCAL 2  /* Wait for local transactions */
#define ACI_DBSHUTDOWN_IMMEDIATE           3      /* Terminate and roll back */
#define ACI_DBSHUTDOWN_ABORT              4 /* Terminate and don't roll back */
#define ACI_DBSHUTDOWN_FINAL              5              /* Orderly shutdown */

/*------------------------- Version information -----------------------------*/
#define ACI_MAJOR_VERSION  7                       /* Major release version */
#define ACI_MINOR_VERSION  0                       /* Minor release version */


#ifndef SQLDEF 

/* input data types */
#define SQLT_CHR  1                        /* (ORANET TYPE) character string */
#define SQLT_NUM  2                          /* (ORANET TYPE) oracle numeric */
#define SQLT_INT  3                                 /* (ORANET TYPE) integer */
#define SQLT_FLT  4                   /* (ORANET TYPE) Floating point number */
#define SQLT_STR  5                                /* zero terminated string */
#define SQLT_VNU  6                        /* NUM with preceding length byte */
#define SQLT_PDN  7                  /* (ORANET TYPE) Packed Decimal Numeric */
#define SQLT_LNG  8                                                  /* long */
#define SQLT_VCS  9                             /* Variable character string */
#define SQLT_NON  10                      /* Null/empty PCC Descriptor entry */
#define SQLT_RID  11                                                /* rowid */
#define SQLT_DAT  12                                /* date in oracle format */
#define SQLT_VBI  15                                 /* binary in VCS format */
#define SQLT_BFLOAT 21                                /* Native Binary float*/
#define SQLT_BDOUBLE 22                             /* NAtive binary double */
#define SQLT_BIN  23                                  /* binary data(DTYBIN) */
#define SQLT_LBI  24                                          /* long binary */
#define SQLT_UIN  68                                     /* unsigned integer */
#define SQLT_SLS  91                        /* Display sign leading separate */
#define SQLT_LVC  94                                  /* Longer longs (char) */
#define SQLT_LVB  95                                   /* Longer long binary */
#define SQLT_AFC  96                                      /* Ansi fixed char */
#define SQLT_AVC  97                                        /* Ansi Var char */
#define SQLT_IBFLOAT  100                          /* binary float canonical */
#define SQLT_IBDOUBLE 101                         /* binary double canonical */
#define SQLT_CUR  102                                        /* cursor  type */
#define SQLT_RDD  104                                    /* rowid descriptor */
#define SQLT_LAB  105                                          /* label type */
#define SQLT_OSL  106                                        /* oslabel type */

#define SQLT_NTY  108                                   /* named object type */
#define SQLT_REF  110                                            /* ref type */
#define SQLT_CLOB 112                                       /* character lob */
#define SQLT_BLOB 113                                          /* binary lob */
#define SQLT_BFILEE 114                                   /* binary file lob */
#define SQLT_CFILEE 115                                /* character file lob */
#define SQLT_RSET 116                                     /* result set type */
#define SQLT_JSON 119                                        /* JSon type */
#define SQLT_NCO  122      /* named collection type (varray or nested table) */
#define SQLT_VST  155                                      /* OCIString type */
#define SQLT_ODT  156                                        /* OCIDate type */

/* datetimes and intervals */
#define SQLT_DATE                      184                      /* ANSI Date */
#define SQLT_TIME                      185                           /* TIME */
#define SQLT_TIME_TZ                   186            /* TIME WITH TIME ZONE */
#define SQLT_TIMESTAMP                 187                      /* TIMESTAMP */
#define SQLT_TIMESTAMP_TZ              188       /* TIMESTAMP WITH TIME ZONE */
#define SQLT_INTERVAL_YM               189         /* INTERVAL YEAR TO MONTH */
#define SQLT_INTERVAL_DS               190         /* INTERVAL DAY TO SECOND */
#define SQLT_TIMESTAMP_LTZ             232        /* TIMESTAMP WITH LOCAL TZ */

#define SQLT_PNTY   241              /* pl/sql representation of named types */

/* some pl/sql specific types */
#define SQLT_REC    250                     /* pl/sql 'record' (or %rowtype) */
#define SQLT_TAB    251                            /* pl/sql 'indexed table' */
#define SQLT_BOL    252                                  /* pl/sql 'boolean' */

/* cxcheng: this has been added for backward compatibility -
   it needs to be here because ocidfn.h can get included ahead of sqldef.h */
#define SQLT_FILE SQLT_BFILEE                             /* binary file lob */
#define SQLT_CFILE SQLT_CFILEE
#define SQLT_BFILE SQLT_BFILEE
 
/* CHAR/NCHAR/VARCHAR2/NVARCHAR2/CLOB/NCLOB char set "form" information */
#define SQLCS_IMPLICIT 1     /* for CHAR, VARCHAR2, CLOB w/o a specified set */
#define SQLCS_NCHAR    2                  /* for NCHAR, NCHAR VARYING, NCLOB */
#define SQLCS_EXPLICIT 3   /* for CHAR, etc, with "CHARACTER SET ..." syntax */
#define SQLCS_FLEXIBLE 4                 /* for PL/SQL "flexible" parameters */
#define SQLCS_LIT_NULL 5      /* for typecheck of NULL and empty_clob() lits */

#endif  /* SQLDEF */

#ifndef ACI_FLAGS 
#define ACI_FLAGS

/* OCI_*_PIECE defines the piece types that are returned or set
*/
#define ACI_ONE_PIECE   0                 /* there or this is the only piece */
#define ACI_FIRST_PIECE 1                        /* the first of many pieces */
#define ACI_NEXT_PIECE  2                         /* the next of many pieces */
#define ACI_LAST_PIECE  3                   /* the last piece of this column */
#endif

/*----------------------------- ACIDateCheck --------------------------------*/

/* Listing of error bits used by ACIDateCheck() */
#define ACI_DATE_INVALID_DAY            0x1                       /* Bad DAy */
#define ACI_DATE_DAY_BELOW_VALID        0x2   /* Bad DAy Low/high bit (1=low)*/
#define ACI_DATE_INVALID_MONTH          0x4                     /* Bad MOnth */
#define ACI_DATE_MONTH_BELOW_VALID      0x8 /* Bad MOnth Low/high bit (1=low)*/
#define ACI_DATE_INVALID_YEAR           0x10                     /* Bad YeaR */
#define ACI_DATE_YEAR_BELOW_VALID       0x20 /* Bad YeaR Low/high bit (1=low)*/
#define ACI_DATE_INVALID_HOUR           0x40                     /* Bad HouR */
#define ACI_DATE_HOUR_BELOW_VALID       0x80 /* Bad HouR Low/high bit (1=low)*/
#define ACI_DATE_INVALID_MINUTE         0x100                  /* Bad MiNute */
#define ACI_DATE_MINUTE_BELOW_VALID     0x200/* Bad MiNute Low/high bit (1=low)*/
#define ACI_DATE_INVALID_SECOND         0x400                  /* Bad SeCond */
#define ACI_DATE_SECOND_BELOW_VALID     0x800/* bad second Low/high bit (1=low)*/
#define ACI_DATE_DAY_MISSING_FROM_1582  0x1000/* Day is one of those "missing" from 1582 */
#define ACI_DATE_YEAR_ZERO              0x2000    /* Year may not equal zero */
#define ACI_DATE_INVALID_FORMAT         0x8000      /* Bad date format input */

typedef struct OCIDate OCIDate;

#include "aciobj.h"

#include "aciapi.h"

#ifndef COMPILE_OCI_LIB
#include "acidef.h"
#endif

#include "aciext.h"

/*****************************************************************************/
/*                             ORACLE DATE TYPE                              */
/*****************************************************************************/
 
struct OCITime
{
  ub1 OCITimeHH;                          /* hours; range is 0 <= hours <=23 */
  ub1 OCITimeMI;                     /* minutes; range is 0 <= minutes <= 59 */
  ub1 OCITimeSS;                     /* seconds; range is 0 <= seconds <= 59 */
};
typedef struct OCITime OCITime;

/* 
 * OCITime - OCI TiMe portion of date
 *
 * This structure should be treated as an opaque structure as the format
 * of this structure may change. Use OCIDateGetTime/OCIDateSetTime 
 * to manipulate time portion of OCIDate.
 */

struct OCIDate
{
  sb2 OCIDateYYYY;         /* gregorian year; range is -4712 <= year <= 9999 */
  ub1 OCIDateMM;                          /* month; range is 1 <= month < 12 */
  ub1 OCIDateDD;                             /* day; range is 1 <= day <= 31 */
  OCITime OCIDateTime;                                               /* time */
};

#define ACI_NUMBER_UNSIGNED 0                        /* Unsigned type -- ubX */
#define ACI_NUMBER_SIGNED   2                          /* Signed type -- sbX */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#define ACI_LASTINSERTID_LEN 32                          /*LAST_INSERT_ID len*/