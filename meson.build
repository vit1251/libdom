project('libdom', 'c', version: '0.1.0')

sources = [
    'src/attr.c',
    'src/dom_doc.c',
    'src/dom_node.c',
    'src/dom_repr.c',
    'src/dump.c',
    'src/util.c',
]

incdir = include_directories('include')

libdom = static_library('libdom', sources,
        include_directories : incdir,
    )

executable('dom', 'src/main.c',
        include_directories: [ incdir ],
        link_with: [ libdom ],
    )

test('DOM Document', executable('01_dom_doc', 'test/01_dom_doc.c', link_with: [libdom], include_directories : incdir, ))
test('DOM Node', executable('02_dom_node', 'test/02_dom_node.c', link_with: [libdom], include_directories : incdir, ))
