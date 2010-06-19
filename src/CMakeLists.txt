Set (
    SOURCES
    type/pabasics.cpp
    type/pastring.cpp
    type/color.cpp
    type/size.cpp
    type/puid.cpp
    type/entity.cpp
    type/item.cpp
    type/creature.cpp
    type/surface.cpp
    type/terrain.cpp
    container/entitycontainer.cpp
    container/world.cpp
    interface/terminal.cpp
    interface/cursor.cpp
    interface/interface.cpp
    wall.cpp
    material.cpp
    tree.cpp
    woodlog.cpp
    race/race.cpp
    race/humanoid.cpp
    pa_engine.cpp
    main.cpp
)

ADD_EXECUTABLE(
    ../pandora
    ${SOURCES}
)

