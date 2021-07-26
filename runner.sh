#!/bin/sh

cppcheck ./dreg \
    --enable=all \
    --inconclusive \
    --verbose \
    --check-config \
    --suppress=missingIncludeSystem . \
    --error-exitcode=255
