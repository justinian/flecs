#include <cpp_api.h>

void World_multi_world_empty() {
    flecs::world *w1 = new flecs::world();
    delete w1;
    flecs::world *w2 = new flecs::world();
    delete w2;

    test_assert(true);
}

void World_multi_world_component() {
    flecs::world w1;
    flecs::world w2;

    auto p_1 = w1.component<Position>();
    auto v_1 = w1.component<Velocity>();
    auto v_2 = w2.component<Velocity>();
    auto m_2 = w2.component<Mass>();

    test_assert(v_1.id() == v_2.id());
    test_assert(p_1.id() != m_2.id());
    test_assert(m_2.id() > v_2.id());

    auto p_2 = w2.component<Position>();
    test_assert(p_1.id() == p_2.id());
}
