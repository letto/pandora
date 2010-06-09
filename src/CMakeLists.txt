Set (
    SOURCES
    pa_basics.cpp
    pa_object.cpp
    puid.cpp
    interface/terminal.cpp
    interface/cursor.cpp
    interface/interface.cpp
    surface.cpp
    terrain.cpp
    world.cpp
    entity.cpp
    entitycontainer.cpp
    wall.cpp
    item.cpp
    material.cpp
    tree.cpp
    woodlog.cpp
    creature.cpp
    race/humanoid.cpp
    race/human.cpp
    race/orc.cpp
    race/elf.cpp
    pa_engine.cpp
    main.cpp
)

ADD_EXECUTABLE(
    ../pandora main.cpp
    ${SOURCES}
)

