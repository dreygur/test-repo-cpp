#!/bin/sh

cppcheck ./dreg \
    --enable=all \
    --inconclusive \
    --verbose \
    --check-config
    --error-exitcode=255
