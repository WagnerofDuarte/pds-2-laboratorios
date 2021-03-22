#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "game_of_life.h"

TEST_CASE("Tests GameOfLife::Enliven(int i, int j)") {
  GameOfLife g(3, 3);
  g.Enliven(0, 0);
  g.Enliven(0, 2);
  g.Enliven(2, 0);
  g.Enliven(2, 2);
  g.Enliven(1, 1);

  // Checa se a céculas solicitadas estão vivas.
  CHECK(g.alive(0, 0));
  CHECK(g.alive(0, 2));
  CHECK(g.alive(2, 0));
  CHECK(g.alive(2, 2));
  CHECK(g.alive(1, 1));
     
  // Checa se as demais céculas continuam mortas.
  CHECK_FALSE(g.alive(0, 1));
  CHECK_FALSE(g.alive(1, 0));
  CHECK_FALSE(g.alive(1, 2));
  CHECK_FALSE(g.alive(2, 1));
}

TEST_CASE("Tests GameOfLife::Kill(int i, int j)") {
  GameOfLife g(3, 3);
  for (int i : {0, 1, 2}) {
      for (int j : {0, 1, 2}) {
        g.Enliven(i, j);
      }
  }

  // Mata um subconjunto de células.
  g.Kill(0, 0);
  g.Kill(0, 2);
  g.Kill(2, 0);
  g.Kill(2, 2);
  g.Kill(1, 1);

  // Checa se a céculas solicitadas estão mortas.
  CHECK_FALSE(g.alive(0, 0));
  CHECK_FALSE(g.alive(0, 2));
  CHECK_FALSE(g.alive(2, 0));
  CHECK_FALSE(g.alive(2, 2));
  CHECK_FALSE(g.alive(1, 1));
    
  // Checa se as demais céculas continuam vivas.
  CHECK(g.alive(0, 1));
  CHECK(g.alive(1, 0));
  CHECK(g.alive(1, 2));
  CHECK(g.alive(2, 1));
}

TEST_CASE("Tests GameOfLife::operator++(int)") {
  
  GameOfLife matrizA(5,5);
  GameOfLife matrizB(5,5);

  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if((i<3 && j>1) || (i>2 && j<1)){
        matrizA.Enliven(i,j);
        CHECK(matrizA.alive(i,j));
      } else {
        matrizA.Kill(i,j);
        CHECK_FALSE(matrizA.alive(i,j));
      }
    }
  }

  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if((j<2) || (j==3 && i>2)){
        matrizB.Enliven(i,j);
        CHECK(matrizB.alive(i,j));
      } else {
        matrizB.Kill(i,j);
        CHECK_FALSE(matrizB.alive(i,j));
      }
    }
  }

  matrizA++;

  for(int i = 0; i < 5; i++){
    for(int j = 0; i < 5; i++){
      CHECK(matrizA.alive(i,j) == matrizB.alive(i,j));
      //CHECK(matrizB.alive(i,j) == matrizA.alive(i,j));
    }
  }

}

TEST_CASE("Test the throwing of GameOfLife::OutOfBoundException") {
  GameOfLife g(3, 3);
  for (int i : {-1, 0, 3}) {
    for (int j : {-1, 0, 3}) {
      if (i != 0 || j != 0) {
        CHECK_THROWS_AS(g.Enliven(i, j), const GameOfLife::InvalidCellException&); 
        CHECK_THROWS_AS(g.Kill(i, j), const GameOfLife::InvalidCellException&);
        CHECK_THROWS_AS(g.alive(i, j), const GameOfLife::InvalidCellException&);
      }
    }
  }
  
}