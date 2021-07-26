#!/bin/sh

cppcheck . \
    --enable=all \
    --inconclusive \
    --verbose \
    --check-config
    --error-exitcode=255
