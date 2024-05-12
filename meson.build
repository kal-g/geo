project('geo', 'cpp', default_options: ['cpp_std=c++20'])

fs = import('fs')

add_project_arguments('-Dmmacosx-version-min=14.0', language: 'cpp')

glutDep = dependency('glut')
openGLDep = dependency('appleframeworks', modules: ['OpenGL'])
sdl2Dep = dependency('sdl2')
glewDep = dependency('glew')
cocoaDep = dependency('Cocoa')

copy = fs.copyfile('images/earth2048.bmp', 'earth2048.bmp')

executable(
    'geo',
    sources: ['src/Bmp.cpp', 'src/Sphere.cpp', 'src/main.cpp'],
    dependencies: [glutDep, openGLDep, sdl2Dep, glewDep, cocoaDep],
    link_args: '-mmacosx-version-min=14.0',
)