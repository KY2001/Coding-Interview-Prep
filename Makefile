# Task
.PHONY: install-uv
install-uv:
	curl -LsSf https://astral.sh/uv/install.sh | sh

.PHONY:
cpplint:
	uvx cpplint@latest --recursive .
