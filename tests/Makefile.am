
SUBDIRS = \
	unboxingdata \
	testutils \
	unboxer

EXTRA_DIST = testdata
dist-hook:
	rm -rf `find $(distdir)/testdata -type d -name .svn`

