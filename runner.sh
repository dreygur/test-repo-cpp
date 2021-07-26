#!/bin/sh

cppcheck . \
    --enable=all \
    --error-exitcode=255
