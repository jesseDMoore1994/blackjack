project(blackjack)
add_library(blackjack_lib STATIC 
    card.cpp card.hpp
    deck.cpp deck.hpp 
    player.cpp player.hpp
    game.cpp game.hpp
)
target_include_directories(blackjack_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(blackjack main.cpp)
install(
    TARGETS blackjack 
    RUNTIME DESTINATION bin
    DESTINATION ${BLACKJACK_INSTALL_BIN_DIR}
)
target_link_libraries(blackjack PRIVATE blackjack_lib)
