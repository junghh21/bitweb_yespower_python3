from setuptools import setup, Extension

y1_module = Extension('y1',
				sources = [	'yespower-module.c',
										'yespower.c',
										'yespower-opt.c',
										'sha256.c',
										'blake2b.c',
									],
				extra_compile_args=['-O3', '-DNDEBUG', '-s', '-funroll-loops', '-fomit-frame-pointer'],
				include_dirs=['.'])

setup (name = 'y1',
	version = '1.0',
	author_email = '',
	author = '',
	url = '',
	description = '',
	ext_modules = [y1_module])
