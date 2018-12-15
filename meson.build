project('libdom', 'c', version: '0.1.0')

sources = [
    'src/attr.c',
    'src/dom.c',
    'src/dump.c',
    'src/util.c',
]

incdir = include_directories('include')

libdom = static_library('libdom', sources,
        include_directories : incdir,
    )

test('Document', executable('01_doc', 'test/01_doc.c', link_with: [libdom], include_directories : incdir, ))
