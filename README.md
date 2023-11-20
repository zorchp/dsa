# dsa
Date structure and Algorithm with Python ,C and C++


times in msec
 clock   self+sourced   self:  sourced script
 clock   elapsed:              other lines

000.007  000.007: --- NVIM STARTING ---
000.119  000.112: event init
000.240  000.120: early init
000.640  000.401: locale set
000.681  000.041: init first window
000.961  000.280: inits 1
000.975  000.014: window checked
000.976  000.002: parsing arguments
001.373  000.051  000.051: require('vim.shared')
001.458  000.032  000.032: require('vim._options')
001.460  000.084  000.051: require('vim._editor')
001.461  000.184  000.049: require('vim._init_packages')
001.462  000.302: init lua interpreter
003.131  001.668: expanding arguments
003.144  000.014: inits 2
003.370  000.225: init highlight
003.371  000.001: waiting for UI
003.471  000.100: done waiting for UI
003.474  000.003: clear screen
003.600  000.126: init default mappings & autocommands
004.110  000.054  000.054: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/ftplugin.vim
004.197  000.024  000.024: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/indent.vim
004.851  000.235  000.235: require('modules.utils')
005.031  000.513  000.279: require('core.settings')
005.143  000.110  000.110: require('core.global')
005.665  000.487  000.487: require('core.options')
006.002  000.160  000.160: require('keymap.bind')
006.623  000.956  000.796: require('core.mapping')
006.772  000.073  000.073: require('keymap.helpers')
007.208  000.102  000.102: require('keymap.completion')
007.472  000.263  000.263: require('keymap.editor')
007.524  000.051  000.051: require('keymap.lang')
007.905  000.380  000.380: require('keymap.tool')
008.123  000.217  000.217: require('keymap.ui')
008.256  001.632  000.545: require('keymap')
008.882  000.625  000.625: require('core.event')
009.138  000.113  000.113: require('modules.utils.icons')
009.517  000.087  000.087: require('completion.lsp')
009.590  000.072  000.072: require('completion.lsp-signature')
009.734  000.142  000.142: require('completion.lspsaga')
009.817  000.082  000.082: require('completion.aerial')
009.924  000.106  000.106: require('completion.glance')
010.027  000.102  000.102: require('completion.null-ls')
010.175  000.147  000.147: require('completion.cmp')
010.247  000.071  000.071: require('completion.luasnip')
010.315  000.066  000.066: require('completion.copilot')
010.375  000.059  000.059: require('completion.copilot-cmp')
010.377  001.024  000.091: require('modules/plugins/completion')
010.606  000.071  000.071: require('editor.accelerated-jk')
010.685  000.077  000.077: require('editor.persisted')
010.775  000.089  000.089: require('editor.autoclose')
010.853  000.077  000.077: require('editor.better-escape')
010.944  000.090  000.090: require('editor.bigfile')
011.023  000.077  000.077: require('editor.flash')
011.098  000.073  000.073: require('editor.comment')
011.159  000.059  000.059: require('editor.hop')
011.226  000.065  000.065: require('editor.vim-illuminate')
011.287  000.061  000.061: require('editor.suda')
011.378  000.090  000.090: require('editor.treesitter')
011.460  000.080  000.080: require('editor.rainbow_delims')
011.524  000.062  000.062: require('editor.ts-context')
011.584  000.060  000.060: require('editor.autotag')
011.644  000.058  000.058: require('editor.colorizer')
011.717  000.073  000.073: require('editor.tabout')
011.718  001.263  000.101: require('modules/plugins/editor')
011.903  000.072  000.072: require('lang.vim-go')
012.006  000.102  000.102: require('lang.rust-tools')
012.128  000.121  000.121: require('lang.crates')
012.130  000.356  000.061: require('modules/plugins/lang')
012.377  000.145  000.145: require('tool.nvim-tree')
012.524  000.146  000.146: require('tool.smartyank')
012.598  000.073  000.073: require('tool.sniprun')
012.684  000.085  000.085: require('tool.toggleterm')
012.781  000.096  000.096: require('tool.trouble')
012.882  000.100  000.100: require('tool.which-key')
013.018  000.135  000.135: require('tool.wilder')
013.184  000.164  000.164: require('tool.telescope')
013.276  000.091  000.091: require('tool.project')
013.443  000.162  000.162: require('tool.dap')
014.453  000.138  000.138: require('tool.dap.dapui')
014.454  002.305  000.969: require('modules/plugins/tool')
014.704  000.154  000.154: require('ui.alpha')
014.795  000.089  000.089: require('ui.bufferline')
014.944  000.148  000.148: require('ui.catppuccin')
015.010  000.064  000.064: require('ui.fidget')
015.090  000.079  000.079: require('ui.gitsigns')
015.172  000.081  000.081: require('ui.indent-blankline')
015.400  000.227  000.227: require('ui.lualine')
015.462  000.061  000.061: require('ui.neodim')
015.525  000.061  000.061: require('ui.neoscroll')
015.596  000.070  000.070: require('ui.notify')
015.657  000.059  000.059: require('ui.paint')
015.721  000.063  000.063: require('ui.scrollview')
015.783  000.060  000.060: require('ui.specs')
015.784  001.309  000.092: require('modules/plugins/ui')
016.319  000.409  000.409: require('lazy')
016.339  000.014  000.014: require('ffi')
016.360  000.020  000.020: require('vim.loader')
016.415  000.014  000.014: require('vim.fs')
016.542  000.163  000.149: require('lazy.stats')
016.662  000.094  000.094: require('lazy.core.util')
016.750  000.087  000.087: require('lazy.core.config')
016.934  000.100  000.100: require('lazy.core.handler')
017.036  000.100  000.100: require('lazy.core.plugin')
017.043  000.292  000.092: require('lazy.core.loader')
019.880  000.148  000.148: require('lazy.core.handler.event')
020.043  000.159  000.159: require('lazy.core.handler.ft')
020.153  000.087  000.087: require('lazy.core.handler.keys')
020.231  000.074  000.074: require('lazy.core.handler.cmd')
020.419  000.013  000.013: sourcing /Users/zorch/.local/share/nvim/site/lazy/csv.vim/ftdetect/csv.vim
020.580  000.096  000.096: require('vim.inspect')
020.990  000.047  000.047: sourcing /Users/zorch/.local/share/nvim/site/lazy/vim-go/ftdetect/gofiletype.vim
022.651  000.196  000.196: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/filetype.lua
026.201  000.092  000.092: require('catppuccin')
026.683  000.063  000.063: require('catppuccin.lib.hashing')
027.759  000.166  000.166: require('bigfile.features')
027.762  000.262  000.096: require('bigfile')
027.950  000.050  000.050: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/editorconfig.lua
028.007  000.012  000.012: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/gzip.vim
028.095  000.007  000.007: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/health.vim
028.206  000.065  000.065: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/man.lua
028.260  000.009  000.009: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/matchit.vim
028.312  000.007  000.007: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/matchparen.vim
028.574  000.217  000.217: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/netrwPlugin.vim
028.671  000.045  000.045: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/nvim.lua
028.876  000.152  000.152: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/rplugin.vim
028.970  000.041  000.041: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/shada.vim
029.029  000.007  000.007: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/spellfile.vim
029.090  000.010  000.010: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/tarPlugin.vim
029.148  000.007  000.007: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/tohtml.vim
029.213  000.011  000.011: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/tutor.vim
029.275  000.010  000.010: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/zipPlugin.vim
029.434  000.042  000.042: sourcing /Users/zorch/.local/share/nvim/site/lazy/bigfile.nvim/after/plugin/bigfile.lua
029.933  021.051  011.675: require('core.pack')
031.770  000.840  000.840: sourcing /Users/zorch/.local/share/nvim/site/lazy/catppuccin/colors/catppuccin.vim
031.775  027.431  001.217: require('core')
031.797  027.471  000.040: sourcing /Users/zorch/.config/nvim/init.lua
031.801  000.652: sourcing vimrc file(s)
031.923  000.043  000.043: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/filetype.lua
032.140  000.047  000.047: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/syntax/synload.vim
032.191  000.180  000.134: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/syntax/syntax.vim
032.200  000.176: inits 3
032.381  000.181: reading ShaDa
032.753  000.008  000.008: require('vim.F')
032.769  000.321  000.312: require('alpha.themes.dashboard')
032.852  000.075  000.075: require('catppuccin.palettes')
032.922  000.068  000.068: require('catppuccin.palettes.mocha')
033.121  000.119  000.119: require('vim.version')
035.684  000.118  000.118: require('alpha')
035.735  002.653: opening buffers
035.749  000.014: BufEnter autocommands
035.751  000.002: editing files in windows
035.841  000.006  000.006: require('vim.keymap')
037.898  002.141: VimEnter autocommands
039.932  002.034: UIEnter autocommands
040.159  000.135  000.135: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/autoload/provider/clipboard.vim
040.163  000.096: before starting main loop
040.361  000.090  000.090: sourcing /Users/zorch/.local/share/nvim/site/lazy/vim-cool/plugin/cool.vim
040.599  000.010  000.010: sourcing /Users/zorch/.local/share/nvim/site/lazy/specs.nvim/plugin/specs.vim
040.870  000.259  000.259: require('specs')
041.409  000.886: first screen update
041.410  000.001: --- NVIM STARTED ---


times in msec
 clock   self+sourced   self:  sourced script
 clock   elapsed:              other lines

000.008  000.008: --- NVIM STARTING ---
000.102  000.094: event init
000.258  000.156: early init
000.755  000.497: locale set
000.809  000.054: init first window
001.233  000.424: inits 1
001.243  000.010: window checked
001.245  000.003: parsing arguments
001.803  000.055  000.055: require('vim.shared')
001.926  000.043  000.043: require('vim._options')
001.928  000.122  000.078: require('vim._editor')
001.930  000.249  000.072: require('vim._init_packages')
001.933  000.438: init lua interpreter
002.350  000.418: expanding arguments
002.366  000.016: inits 2
002.671  000.305: init highlight


times in msec
 clock   self+sourced   self:  sourced script
 clock   elapsed:              other lines

000.006  000.006: --- NVIM STARTING ---
000.085  000.079: event init
000.206  000.122: early init
000.586  000.379: locale set
000.631  000.046: init first window
000.909  000.277: inits 1
000.924  000.015: window checked
000.926  000.002: parsing arguments
001.351  000.060  000.060: require('vim.shared')
001.458  000.043  000.043: require('vim._options')
001.459  000.106  000.063: require('vim._editor')
001.461  000.213  000.047: require('vim._init_packages')
001.463  000.324: init lua interpreter
003.702  002.240: expanding arguments
003.720  000.018: inits 2
003.977  000.256: init highlight
003.978  000.001: waiting for UI
004.096  000.118: done waiting for UI
004.100  000.004: clear screen
004.256  000.156: init default mappings & autocommands
004.868  000.073  000.073: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/ftplugin.vim
004.975  000.030  000.030: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/indent.vim
005.791  000.276  000.276: require('modules.utils')
006.009  000.615  000.339: require('core.settings')
006.130  000.119  000.119: require('core.global')
006.709  000.540  000.540: require('core.options')
007.065  000.167  000.167: require('keymap.bind')
007.702  000.992  000.824: require('core.mapping')
007.873  000.083  000.083: require('keymap.helpers')
008.325  000.192  000.192: require('keymap.completion')
008.593  000.267  000.267: require('keymap.editor')
008.661  000.066  000.066: require('keymap.lang')
009.205  000.543  000.543: require('keymap.tool')
009.413  000.206  000.206: require('keymap.ui')
009.570  001.867  000.509: require('keymap')
010.243  000.672  000.672: require('core.event')
010.574  000.134  000.134: require('modules.utils.icons')
011.006  000.101  000.101: require('completion.lsp')
011.094  000.086  000.086: require('completion.lsp-signature')
011.266  000.170  000.170: require('completion.lspsaga')
011.368  000.101  000.101: require('completion.aerial')
011.491  000.122  000.122: require('completion.glance')
011.604  000.111  000.111: require('completion.null-ls')
011.781  000.176  000.176: require('completion.cmp')
011.867  000.085  000.085: require('completion.luasnip')
011.960  000.091  000.091: require('completion.copilot')
012.029  000.068  000.068: require('completion.copilot-cmp')
012.030  001.209  000.098: require('modules/plugins/completion')
012.267  000.079  000.079: require('editor.accelerated-jk')
012.359  000.091  000.091: require('editor.persisted')
012.445  000.085  000.085: require('editor.autoclose')
012.515  000.069  000.069: require('editor.better-escape')
012.600  000.084  000.084: require('editor.bigfile')
012.683  000.081  000.081: require('editor.flash')
012.777  000.093  000.093: require('editor.comment')
012.869  000.081  000.081: require('editor.hop')
012.960  000.091  000.091: require('editor.vim-illuminate')
013.030  000.068  000.068: require('editor.suda')
013.128  000.097  000.097: require('editor.treesitter')
013.225  000.097  000.097: require('editor.rainbow_delims')
013.300  000.073  000.073: require('editor.ts-context')
013.366  000.066  000.066: require('editor.autotag')
013.441  000.073  000.073: require('editor.colorizer')
013.516  000.074  000.074: require('editor.tabout')
013.517  001.414  000.113: require('modules/plugins/editor')
013.743  000.081  000.081: require('lang.vim-go')
013.854  000.110  000.110: require('lang.rust-tools')
013.989  000.134  000.134: require('lang.crates')
013.990  000.385  000.061: require('modules/plugins/lang')
014.368  000.229  000.229: require('tool.nvim-tree')
014.448  000.079  000.079: require('tool.smartyank')
014.534  000.085  000.085: require('tool.sniprun')
014.623  000.087  000.087: require('tool.toggleterm')
014.729  000.105  000.105: require('tool.trouble')
014.825  000.095  000.095: require('tool.which-key')
014.942  000.115  000.115: require('tool.wilder')
015.104  000.161  000.161: require('tool.telescope')
015.203  000.098  000.098: require('tool.project')
015.369  000.161  000.161: require('tool.dap')
015.552  000.144  000.144: require('tool.dap.dapui')
015.553  001.502  000.142: require('modules/plugins/tool')
015.881  000.156  000.156: require('ui.alpha')
015.984  000.102  000.102: require('ui.bufferline')
016.147  000.162  000.162: require('ui.catppuccin')
016.224  000.076  000.076: require('ui.fidget')
016.324  000.098  000.098: require('ui.gitsigns')
016.418  000.093  000.093: require('ui.indent-blankline')
016.678  000.258  000.258: require('ui.lualine')
016.752  000.073  000.073: require('ui.neodim')
016.828  000.075  000.075: require('ui.neoscroll')
016.918  000.089  000.089: require('ui.notify')
016.987  000.067  000.067: require('ui.paint')
017.066  000.077  000.077: require('ui.scrollview')
017.142  000.076  000.076: require('ui.specs')
017.143  001.527  000.124: require('modules/plugins/ui')
017.985  000.484  000.484: require('lazy')
018.002  000.010  000.010: require('ffi')
018.023  000.019  000.019: require('vim.loader')
018.076  000.014  000.014: require('vim.fs')
018.202  000.163  000.149: require('lazy.stats')
018.302  000.077  000.077: require('lazy.core.util')
018.425  000.122  000.122: require('lazy.core.config')
018.572  000.069  000.069: require('lazy.core.handler')
018.664  000.091  000.091: require('lazy.core.plugin')
018.668  000.242  000.083: require('lazy.core.loader')
021.983  000.128  000.128: require('lazy.core.handler.keys')
022.126  000.141  000.141: require('lazy.core.handler.cmd')
022.264  000.134  000.134: require('lazy.core.handler.event')
022.340  000.074  000.074: require('lazy.core.handler.ft')
022.546  000.050  000.050: sourcing /Users/zorch/.local/share/nvim/site/lazy/vim-go/ftdetect/gofiletype.vim
022.642  000.067  000.067: require('vim.inspect')
023.145  000.011  000.011: sourcing /Users/zorch/.local/share/nvim/site/lazy/csv.vim/ftdetect/csv.vim
024.575  000.200  000.200: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/filetype.lua
027.981  000.085  000.085: require('bigfile.features')
027.983  000.175  000.090: require('bigfile')
028.592  000.119  000.119: require('catppuccin')
028.852  000.056  000.056: require('catppuccin.lib.hashing')
029.340  000.048  000.048: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/editorconfig.lua
029.430  000.010  000.010: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/gzip.vim
029.480  000.006  000.006: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/health.vim
029.570  000.043  000.043: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/man.lua
029.625  000.008  000.008: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/matchit.vim
029.676  000.007  000.007: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/matchparen.vim
029.932  000.209  000.209: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/netrwPlugin.vim
030.020  000.038  000.038: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/nvim.lua
030.204  000.132  000.132: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/rplugin.vim
030.299  000.046  000.046: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/shada.vim
030.357  000.006  000.006: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/spellfile.vim
030.415  000.009  000.009: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/tarPlugin.vim
030.471  000.006  000.006: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/tohtml.vim
030.532  000.011  000.011: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/tutor.vim
030.592  000.009  000.009: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/plugin/zipPlugin.vim
030.720  000.034  000.034: sourcing /Users/zorch/.local/share/nvim/site/lazy/bigfile.nvim/after/plugin/bigfile.lua
031.220  020.976  011.911: require('core.pack')
032.858  000.692  000.692: sourcing /Users/zorch/.local/share/nvim/site/lazy/catppuccin/colors/catppuccin.vim
032.861  027.693  001.220: require('core')
032.882  027.737  000.044: sourcing /Users/zorch/.config/nvim/init.lua
032.887  000.792: sourcing vimrc file(s)
032.990  000.030  000.030: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/filetype.lua
033.188  000.045  000.045: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/syntax/synload.vim
033.235  000.168  000.123: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/syntax/syntax.vim
033.244  000.159: inits 3
033.422  000.179: reading ShaDa
033.773  000.009  000.009: require('vim.F')
033.785  000.310  000.301: require('alpha.themes.dashboard')
033.868  000.074  000.074: require('catppuccin.palettes')
033.938  000.069  000.069: require('catppuccin.palettes.mocha')
034.100  000.113  000.113: require('vim.version')
036.661  000.109  000.109: require('alpha')
036.744  002.648: opening buffers
036.758  000.014: BufEnter autocommands
036.762  000.004: editing files in windows
036.847  000.005  000.005: require('vim.keymap')
038.762  001.994: VimEnter autocommands
040.376  001.615: UIEnter autocommands
040.603  000.135  000.135: sourcing /opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime/autoload/provider/clipboard.vim
040.607  000.095: before starting main loop
040.726  000.010  000.010: sourcing /Users/zorch/.local/share/nvim/site/lazy/specs.nvim/plugin/specs.vim
041.047  000.306  000.306: require('specs')
041.600  000.090  000.090: sourcing /Users/zorch/.local/share/nvim/site/lazy/vim-cool/plugin/cool.vim
041.906  000.893: first screen update
041.907  000.001: --- NVIM STARTED ---


times in msec
 clock   self+sourced   self:  sourced script
 clock   elapsed:              other lines

000.030  000.030: --- NVIM STARTING ---
000.177  000.146: event init
000.384  000.208: early init
001.031  000.646: locale set
001.085  000.055: init first window
001.590  000.504: inits 1
001.599  000.010: window checked
001.602  000.003: parsing arguments
002.199  000.071  000.071: require('vim.shared')
002.330  000.047  000.047: require('vim._options')
002.333  000.128  000.081: require('vim._editor')
002.335  000.275  000.076: require('vim._init_packages')
002.338  000.460: init lua interpreter
002.730  000.392: expanding arguments
002.749  000.019: inits 2
003.112  000.363: init highlight
