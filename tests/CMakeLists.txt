project(blackjack_tests)
add_subdirectory(Catch2)
add_executable(tests test_card.cpp test_deck.cpp)
install(
    TARGETS tests 
    RUNTIME DESTINATION bin
    DESTINATION ${BLACKJACK_INSTALL_BIN_DIR}
)
target_link_libraries(tests PRIVATE blackjack_lib Catch2::Catch2WithMain)
