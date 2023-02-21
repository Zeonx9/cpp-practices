cmake_minimum_required(VERSION 3.23)
project(cpp_trainings)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        practice_1
        practice_1/main.cpp
)

add_executable(
        practice_2
        practice_2/main.cpp
)

add_executable(
        practice_3
        practice_3/DynArray.h
        practice_3/main.cpp
        practice_3/MyStack.h
)

add_executable(
        practice_4
        practice_4/main.cpp
        practice_4/DynArray.h
        practice_4/Vec3d.h
)

add_executable(
        practice_5
        practice_5/include/Matrix.h
        practice_5/src/Matrix.cpp
        practice_5/include/Vector.h
        practice_5/src/Vector.cpp
        practice_5/main.cpp
        practice_5/src/SLESolver.cpp
        practice_5/include/SLESolver.h
)

add_executable(
        practice_6
        practice_6/include/DynArray.h
        practice_6/src/DynArray.cpp
        practice_6/main.cpp
        practice_6/src/Queue.cpp
        practice_6/include/Queue.h
)

add_executable(
        practice_7
        practice_7/main.cpp
)

add_executable(
        practice_8
        practice_8/main.cpp
        practice_8/LinkedList.h
)

add_executable(
        practice_9
        practice_9/main.cpp
        practice_9/LinkedList.h
)

add_executable(
        practice_10
        practice_10/main.cpp
)

add_executable(
        practice_11
        practice_11/main.cpp
)

add_executable(
        practice_12
        practice_12/main.cpp
        practice_12/graph.h
)

add_executable(
        practice_13
        practice_13/main.cpp
)

add_executable(
        practice_15
        practice_15/main.cpp
        practice_15/shapes/interfaces/Drawable2D.h
        practice_15/shapes/Shape.h
        practice_15/shapes/Rectangle.h
        practice_15/shapes/Circle.h
        practice_15/shapes/Triangle.h
        practice_15/shapes/ShapeFactory.h
        practice_15/shapes/src/Rectangle.cpp
        practice_15/shapes/src/Circle.cpp
        practice_15/shapes/src/Triangle.cpp

        practice_15/chess/util/util.h
        practice_15/chess/render/Renderer.h
        practice_15/chess/render/console/ConsoleDrawable.h
        practice_15/chess/render/console/ConsoleRenderer.h
        practice_15/chess/render/console/ConsoleCell.h
        practice_15/chess/game/Game.h
        practice_15/chess/game/ClassicGame.h
        practice_15/chess/board/Board.h
        practice_15/chess/board/ClassicBoard.h
        practice_15/chess/pieces/Piece.h
        practice_15/chess/pieces/Pawn.h
        practice_15/chess/pieces/Rook.h
        practice_15/chess/pieces/Knight.h
        practice_15/chess/pieces/Bishop.h
        practice_15/chess/pieces/Queen.h
        practice_15/chess/pieces/King.h
        practice_15/chess/move/Move.h
        practice_15/chess/move/Player.h
)