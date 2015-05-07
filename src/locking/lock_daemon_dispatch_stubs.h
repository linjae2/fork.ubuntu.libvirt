/* Automatically generated from ./locking/lock_protocol.x by gendispatch.pl.
 * Do not edit this file.  Any changes you make will be lost.
 */
static int virLockSpaceProtocolDispatchAcquireResource(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    virLockSpaceProtocolAcquireResourceArgs *args);
static int virLockSpaceProtocolDispatchAcquireResourceHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("virLockSpaceProtocolDispatchAcquireResource");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p", server, client, msg, rerr, args, ret);
  rv = virLockSpaceProtocolDispatchAcquireResource(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* virLockSpaceProtocolDispatchAcquireResource body has to be implemented manually */



static int virLockSpaceProtocolDispatchCreateLockSpace(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    virLockSpaceProtocolCreateLockSpaceArgs *args);
static int virLockSpaceProtocolDispatchCreateLockSpaceHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("virLockSpaceProtocolDispatchCreateLockSpace");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p", server, client, msg, rerr, args, ret);
  rv = virLockSpaceProtocolDispatchCreateLockSpace(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* virLockSpaceProtocolDispatchCreateLockSpace body has to be implemented manually */



static int virLockSpaceProtocolDispatchCreateResource(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    virLockSpaceProtocolCreateResourceArgs *args);
static int virLockSpaceProtocolDispatchCreateResourceHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("virLockSpaceProtocolDispatchCreateResource");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p", server, client, msg, rerr, args, ret);
  rv = virLockSpaceProtocolDispatchCreateResource(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* virLockSpaceProtocolDispatchCreateResource body has to be implemented manually */



static int virLockSpaceProtocolDispatchDeleteResource(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    virLockSpaceProtocolDeleteResourceArgs *args);
static int virLockSpaceProtocolDispatchDeleteResourceHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("virLockSpaceProtocolDispatchDeleteResource");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p", server, client, msg, rerr, args, ret);
  rv = virLockSpaceProtocolDispatchDeleteResource(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* virLockSpaceProtocolDispatchDeleteResource body has to be implemented manually */



static int virLockSpaceProtocolDispatchNew(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    virLockSpaceProtocolNewArgs *args);
static int virLockSpaceProtocolDispatchNewHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("virLockSpaceProtocolDispatchNew");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p", server, client, msg, rerr, args, ret);
  rv = virLockSpaceProtocolDispatchNew(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* virLockSpaceProtocolDispatchNew body has to be implemented manually */



static int virLockSpaceProtocolDispatchRegister(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    virLockSpaceProtocolRegisterArgs *args);
static int virLockSpaceProtocolDispatchRegisterHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("virLockSpaceProtocolDispatchRegister");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p", server, client, msg, rerr, args, ret);
  rv = virLockSpaceProtocolDispatchRegister(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* virLockSpaceProtocolDispatchRegister body has to be implemented manually */



static int virLockSpaceProtocolDispatchReleaseResource(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    virLockSpaceProtocolReleaseResourceArgs *args);
static int virLockSpaceProtocolDispatchReleaseResourceHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("virLockSpaceProtocolDispatchReleaseResource");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p", server, client, msg, rerr, args, ret);
  rv = virLockSpaceProtocolDispatchReleaseResource(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* virLockSpaceProtocolDispatchReleaseResource body has to be implemented manually */



static int virLockSpaceProtocolDispatchRestrict(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    virLockSpaceProtocolRestrictArgs *args);
static int virLockSpaceProtocolDispatchRestrictHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("virLockSpaceProtocolDispatchRestrict");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p", server, client, msg, rerr, args, ret);
  rv = virLockSpaceProtocolDispatchRestrict(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* virLockSpaceProtocolDispatchRestrict body has to be implemented manually */



virNetServerProgramProc virLockSpaceProtocolProcs[] = {
{ /* Unused 0 */
   NULL,
   0,
   (xdrproc_t)xdr_void,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method Register => 1 */
   virLockSpaceProtocolDispatchRegisterHelper,
   sizeof(virLockSpaceProtocolRegisterArgs),
   (xdrproc_t)xdr_virLockSpaceProtocolRegisterArgs,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method Restrict => 2 */
   virLockSpaceProtocolDispatchRestrictHelper,
   sizeof(virLockSpaceProtocolRestrictArgs),
   (xdrproc_t)xdr_virLockSpaceProtocolRestrictArgs,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method New => 3 */
   virLockSpaceProtocolDispatchNewHelper,
   sizeof(virLockSpaceProtocolNewArgs),
   (xdrproc_t)xdr_virLockSpaceProtocolNewArgs,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method CreateResource => 4 */
   virLockSpaceProtocolDispatchCreateResourceHelper,
   sizeof(virLockSpaceProtocolCreateResourceArgs),
   (xdrproc_t)xdr_virLockSpaceProtocolCreateResourceArgs,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method DeleteResource => 5 */
   virLockSpaceProtocolDispatchDeleteResourceHelper,
   sizeof(virLockSpaceProtocolDeleteResourceArgs),
   (xdrproc_t)xdr_virLockSpaceProtocolDeleteResourceArgs,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method AcquireResource => 6 */
   virLockSpaceProtocolDispatchAcquireResourceHelper,
   sizeof(virLockSpaceProtocolAcquireResourceArgs),
   (xdrproc_t)xdr_virLockSpaceProtocolAcquireResourceArgs,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method ReleaseResource => 7 */
   virLockSpaceProtocolDispatchReleaseResourceHelper,
   sizeof(virLockSpaceProtocolReleaseResourceArgs),
   (xdrproc_t)xdr_virLockSpaceProtocolReleaseResourceArgs,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method CreateLockSpace => 8 */
   virLockSpaceProtocolDispatchCreateLockSpaceHelper,
   sizeof(virLockSpaceProtocolCreateLockSpaceArgs),
   (xdrproc_t)xdr_virLockSpaceProtocolCreateLockSpaceArgs,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
};
size_t virLockSpaceProtocolNProcs = ARRAY_CARDINALITY(virLockSpaceProtocolProcs);
