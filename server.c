#include <ctype.h>
#include <rpc/rpc.h>
#include "list.h"

int *suma();
int *mult();
//bool_t xdr_param();
bool_t xdr_nodo();

int r; // resultado de operaciones
main(int argc, char *argv[])
{
  registerrpc(P, V, SUMA, suma, xdr_nodo, xdr_int);
  svc_run();
}

int *suma(param *p)
{
  r = p->numero;
  printf("Estamos en el servidor\n");

  printf("El valor: %d", p->numero);
  /*while (p->numero != 0)
  {
    printf("dentro del while");
    r = r + p->numero;
    p = p->sig;
    printf("Suma: %d",r);
  }*/

  return &r;
}

/*bool_t xdr_param(XDR *xdrp, param *p)
{
  if (xdr_int(xdrp, &(p->numero)) == FALSE)
    return (FALSE);
  return (xdr_int(xdrp, &(p->sig)));
}*/

bool_t xdr_nodo(XDR *xdrp, param *p)
{
  if (!xdr_pointer(xdrp, (char **)&(p->numero), sizeof(param), (xdrproc_t)xdr_nodo))
    return (FALSE);
  if (xdr_int(xdrp, &p->sig) == FALSE)
    return (FALSE);
  return (TRUE);
}