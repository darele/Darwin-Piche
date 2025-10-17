#include "encoder.h"
#include "encoderlib.h"

void encode(int N, int M[])
{
  // Subtarea 1 y 2

  // for (int i = 0; i < N; i++) {
  //   send(M[i] + 256 * i);
  // }

  // Subtarea 1, 2, 3 y 4
  // Enviar la posicion de los bits encencidos y separar en grupos de 8 bits
  for(int i = 0; i < N; i++) {
    int j = 0;
    while (j < 8) {
      if (M[i] & (1 << j)) {
        send(8*i + j);
      }
      j++;
    }
  }

  // Subtarea 5 (no funciono, siempre da 81)
  // Usar los primeros 3 bits para la posicion de los bits encendidos
  // Usar los ultimos 5 bits para la posicion
  // Hacer un envio por cada bit encendido
  // Por ejemplo si el tercer elemento tiene el segundo bit encencido, enviar 011 00010
  // for(int i = 0; i < N; i++) {
  //   int j = 0;
  //   while (j < 8) {
  //     if (M[i] & (1 << j)) {
  //       send((i << 3) + j);
  //     }
  //     j++;
  //   }
  // }
}
