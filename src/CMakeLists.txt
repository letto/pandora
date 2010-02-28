Set (
    SOURCES
    wall.cpp
    pa_basics.cpp
    pa_object.cpp
    surface.cpp
    terrain.cpp
    world.cpp
    entity.cpp
    entitycontainer.cpp
    item.cpp
    material.cpp
    tree.cpp
    woodlog.cpp
    creature.cpp
    race/humanoid.cpp
    race/human.cpp
    race/orc.cpp
    race/elf.cpp
    terminal.cpp
    pa_engine.cpp
    cursor.cpp
    interface.cpp
    main.cpp
)

ADD_EXECUTABLE(
    ../pandora main.cpp
    ${SOURCES}
)

