// Extend jQuery to add a debug console
(function($) {
    $.fn.debug_console = function(eval, options) {
        if ($('body').data('debug_console')) {
            return $('body').data('debug_console').terminal;
        }
        this.addClass('debug_console');
        options = options || {};
        eval = eval || function(command, term) {
            term.echo("No debug command handler set");
        };
        var settings = {
            prompt: 'debug> ',
            name: 'Debug',
            height: 100,
            enabled: false,
            greetings: 'Fyleria debug console',
            keypress: function(e) {
                if (e.which == 96) {
                    return false;
                }
            }
        };
        if (options) {
            $.extend(settings, options);
        }
        this.append('<div class="td"></div>');
        var self = this;
        self.terminal = this.find('.td').terminal(eval, settings);
        var focus = false;
        $(document.documentElement).keypress(function(e) {
            if (e.which == 96) {
                self.slideToggle('fast');
                self.terminal.focus(focus = !focus);
                self.terminal.attr({
                    scrollTop: self.terminal.attr("scrollHeight")
                });
            }
        });
        $('body').data('debug_console', this);
        this.hide();
        return self;
    };
})(jQuery);

// Attach debug console
jQuery(document).ready(function($) {
    $('#debug_console').debug_console(function(command, terminal) {
        terminal.echo('you type command "' + command + '"');
    });
});
